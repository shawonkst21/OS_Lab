#include<bits/stdc++.h>
using namespace std;
struct process
{
    int id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
};
void calculate_COmpletion_time(vector<process> &p,int n)
{
    p[0].completion_time=p[0].arrival_time+p[0].burst_time;
    for(int i=1;i<n;i++)
    {
        if(p[i].arrival_time>p[i-1].completion_time)
            p[i].completion_time=p[i].arrival_time+p[i].burst_time;
        else
            p[i].completion_time=p[i-1].completion_time+p[i].burst_time;
    }
}
void calculate_turnaround_time(vector<process> &p,int n)
{
    for(int i=0;i<n;i++)
        p[i].turnaround_time=p[i].completion_time-p[i].arrival_time;
}
void calculate_waiting_time(vector<process> &p,int n)
{
    for(int i=0;i<n;i++)
        p[i].waiting_time=p[i].turnaround_time-p[i].burst_time;
}
void solve(vector<process> &p,int n)
{
    calculate_COmpletion_time(p,n);
    calculate_turnaround_time(p,n);
    calculate_waiting_time(p,n);
    cout<<"Process ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n";
    for(int i=0;i<n;i++)
    {
        cout<<"\t\t"p[i].id<<"\t\t"<<p[i].arrival_time<<"\t\t"<<p[i].burst_time<<"\t\t"<<p[i].completion_time<<"\t\t"<<p[i].turnaround_time<<"\t\t"<<p[i].waiting_time<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    vector<process> p(n);
    for(int i=0;i<n;i++)
    {
        p[i].id=i+1;
        cin>>p[i].arrival_time>>p[i].burst_time;
    }
    sort(p.begin(),p.end(),[](process a,process b){
        return a.arrival_time<b.arrival_time;
    });
    solve(p,n);
}
