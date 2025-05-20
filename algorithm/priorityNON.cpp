#include<bits/stdc++.h>
using namespace std;
struct process{
    int id;
    int arrival_time;
    int brust_time;
    int completion_time;
    int trun_around_time;
    int waiting_time;
    int priority;
};
void solve(vector<process>&p,int n)
{
    int completed=0;
    int current_time=0;
    bool in_queue[n]={false};
    while(completed<n)
    {
        int idx=-1;
        int higest_prority=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(p[i].arrival_time<=current_time && !in_queue[i])
            {
                if(p[i].priority<higest_prority)
                {
                    higest_prority=p[i].priority;
                    idx=i;
                }
                else if(p[i].priority==higest_prority)
                {
                    if(p[i].arrival_time<p[idx].arrival_time)
                    {
                        idx=i;
                    }
                }
            }
        }
        if(idx!=-1)
        {
            current_time+=p[idx].brust_time;
            p[idx].completion_time=current_time;
            p[idx].trun_around_time=p[idx].completion_time-p[idx].arrival_time;
            p[idx].waiting_time=p[idx].trun_around_time-p[idx].brust_time;
            in_queue[idx]=true;
            completed++;
        }
        else
        {
            current_time++;
        }
    }
}
void display(vector<process>&p,int n)
{
     cout << "Process ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n";
    for (int i = 0; i < n; i++)
    {
        cout << p[i].id << "\t\t"
             << p[i].arrival_time << "\t\t"
             << p[i].brust_time << "\t\t"
             << p[i].completion_time << "\t\t\t"
             << p[i].trun_around_time << "\t\t\t"
             << p[i].waiting_time << endl;
    }
}
int main()
{
    int n;
    cin>>n;
    vector<process>p(n);
    for(int i=0;i<n;i++)
    {
        p[i].id=i+1;
        cin>>p[i].arrival_time>>p[i].brust_time>>p[i].priority;
    }
    solve(p,n);
    display(p,n);
}
