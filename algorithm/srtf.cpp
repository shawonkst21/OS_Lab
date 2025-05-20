#include<bits/stdc++.h>
using namespace std;
struct Process
{
    int id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
};
void findsRTf(vector<Process> &p,int n)
{
    vector<int> remaining_time(n);
    for(int i=0;i<n;i++)
        remaining_time[i]=p[i].burst_time;
        int current_time=0;
        int completed=0;
        int min_burst_time=INT_MAX;
        int min_index=0;
        while(completed<n)
        {
           min_burst_time=INT_MAX;
           for(int i=0;i<n;i++)
           {
               if(p[i].arrival_time<=current_time && remaining_time[i]<min_burst_time && remaining_time[i]>0)
               {
                   min_burst_time=remaining_time[i];
                   min_index=i;
               }
            }
            remaining_time[min_index]--;
            if(remaining_time[min_index]==0)
            {
                completed++;
                p[min_index].completion_time=current_time+1;
                p[min_index].turnaround_time=p[min_index].completion_time-p[min_index].arrival_time;
                p[min_index].waiting_time=p[min_index].turnaround_time-p[min_index].burst_time;
            }
             current_time++;
        }
}
void display(vector<Process> &p, int n)
{
    cout << "Process ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n";
    for (int i = 0; i < n; i++)
    {
        cout << p[i].id << "\t\t"
             << p[i].arrival_time << "\t\t"
             << p[i].burst_time << "\t\t"
             << p[i].completion_time << "\t\t\t"
             << p[i].turnaround_time << "\t\t\t"
             << p[i].waiting_time << endl;
    }
}
int main()
{
    int n;
    cin>>n;
    vector<Process> p(n);
    for(int i=0;i<n;i++)
    {
        p[i].id=i+1;
        cin>>p[i].arrival_time>>p[i].burst_time;
    }
   findsRTf(p,n);
   display(p,n);
    return 0;
}
