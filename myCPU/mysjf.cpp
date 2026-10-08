#include <iostream>
#include <algorithm>

using namespace std;


struct Process {
    int p;
    int bt;
    int wt;
    int tat;
};

bool compare(Process a, Process b) {
    return a.bt < b.bt;
}

int main()
{
int n;
   float awt=0,atat=0;

cout<<"Enter the number of processes:";

cin>>n;
   Process pro[n]{};

   for(int i=0;i<n;i++)
      {
         cout<<"Enter Process and burst time:"<<endl;
         cin>>pro[i].p>>pro[i].bt;
      }
cout<<"\nBefore sorting\n ";
for(int i=0;i<n;i++)
   {
      cout<<pro[i].p<<" burst time "<<pro[i].bt<<endl;
   }

      sort(pro,pro+n,compare);

      cout<<"\nAfter sorting\n ";
for(int i=0;i<n;i++)
   {
      cout<<pro[i].p<<" burst time "<<pro[i].bt<<endl;
   }

   cout<<"PR\tBT\tWT\tTAT\n";
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<i;j++){
         pro[i].wt=pro[i].wt+pro[j].bt;
      }

      pro[i].tat=pro[i].wt+pro[i].bt;
   awt=awt+pro[i].wt;
   atat=atat+pro[i].tat;

   cout<<pro[i].p<<" "<<pro[i].bt<<" "<<pro[i].wt<<" "<<pro[i].tat<<endl;
   }

   awt=awt/n;
   atat=atat/n;
   cout<<"\nAverage waiting time:"<<awt<<endl;
   cout<<"\nAverage turnaround time:"<<atat<<endl;

}
/*
3
1 5
2 2
3 4
*/