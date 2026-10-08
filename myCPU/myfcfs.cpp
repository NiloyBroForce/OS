#include <iostream>
#include <algorithm>

using namespace std;

struct Process
{
    int p;
    int at;
    int bt;
    int wt;
    int tat;
};

bool compare(Process a, Process b)
{
    return a.at < b.at;
}

int main()
{
    int n;
    float awt = 0, atat = 0;

    cout << "Enter the number of processes: ";
    cin >> n;

    Process pro[n]{};

    for (int i = 0; i < n; i++)
    {
        cout << "Enter Process, burst time, arrival time:" << endl;
        cin >> pro[i].p >> pro[i].bt >> pro[i].at;
    }

    sort(pro, pro + n, compare);

    cout << "\nPR\tBT\tAT\tWT\tTAT\n";

    int time = 0;

    for (int i = 0; i < n; i++)
    {
        if (time < pro[i].at)
            time = pro[i].at;

        pro[i].wt = time - pro[i].at;

        time = time + pro[i].bt;

        pro[i].tat = time - pro[i].at;

        awt = awt + pro[i].wt;
        atat = atat + pro[i].tat;

        cout << "P" << pro[i].p << "\t"
             << pro[i].bt << "\t"
             << pro[i].at << "\t"
             << pro[i].wt << "\t"
             << pro[i].tat << endl;
    }

    awt = awt / n;
    atat = atat / n;

    cout << "\nAverage waiting time: " << awt << endl;
    cout << "Average turnaround time: " << atat << endl;
}
/*
3
1 5 3
2 4 1
3 2 2
*/