#include <iostream>
#include <queue>

using namespace std;

struct Process
{
    int p;
    int at;
    int bt;
    int rt;
    int wt;
    int tat;
};

int main()
{
    int n, q;
    float awt = 0, atat = 0;

    cout << "Enter number of processes: ";
    cin >> n;

    Process pro[n]{};

    for (int i = 0; i < n; i++)
    {
        cout << "Enter Process, burst time, arrival time: ";
        cin >> pro[i].p >> pro[i].bt >> pro[i].at;

        pro[i].rt = pro[i].bt;
    }

    cout << "Enter Quantum: ";
    cin >> q;

    queue<int> ready;

    int time = 0;
    int remain = n;
    int i = 0;

    while (remain > 0)
    {
        // Add processes that have arrived
        while (i < n && pro[i].at <= time)
        {
            ready.push(i);
            i++;
        }

        // CPU idle
        if (ready.empty())
        {
            time = pro[i].at;
            continue;
        }

        int curr = ready.front();
        ready.pop();

        // Run curr process
        if (pro[curr].rt <= q)
        {
            time += pro[curr].rt;
            pro[curr].rt = 0;

            pro[curr].tat = time - pro[curr].at;
            pro[curr].wt = pro[curr].tat - pro[curr].bt;

            awt += pro[curr].wt;
            atat += pro[curr].tat;

            remain--;
        }
        else
        {
            time += q;
            pro[curr].rt -= q;
        }

        // Add newly arrived processes
        while (i < n && pro[i].at <= time)
        {
            ready.push(i);
            i++;
        }

        // Put curr process back if unfinished
        if (pro[curr].rt > 0)
        {
            ready.push(curr);
        }
    }

    cout << "\nPR\tBT\tAT\tWT\tTAT\n";

    for (int i = 0; i < n; i++)
    {
        cout << "P" << pro[i].p << "\t"
             << pro[i].bt << "\t"
             << pro[i].at << "\t"
             << pro[i].wt << "\t"
             << pro[i].tat << endl;
    }

    cout << "\nAverage waiting time: " << awt / n;
    cout << "\nAverage turnaround time: " << atat / n;
}
/*
4
1 5 0
2 3 1
3 4 2
4 2 8
2
*/