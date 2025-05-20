#include<bits/stdc++.h>
using namespace std;
struct round_robin
{
    int id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
    int remaining_time;
};
void roundrobin(vector<round_robin> &p,int n,int quantam)
{
    queue<int>q;
    int current_time=0;
    int completed=0;
    bool in_queue[n]={false};
    for(int i=0;i<n;i++)
    {
        p[i].remaining_time=p[i].burst_time;
    }
    while(completed<n)
    {
        for(int i=0;i<n;i++)
        {
            if(p[i].arrival_time<=current_time && !in_queue[i] && p[i].remaining_time>0)
            {
                q.push(i);
                in_queue[i]=true;
            }
            
        }
        if(!q.empty())
        {
            int index=q.front();
            q.pop();
            if(p[index].remaining_time>quantam)
            {
                current_time+=quantam;
                p[index].remaining_time-=quantam;
                for(int i=0;i<n;i++)
                {
                    if(p[i].arrival_time<=current_time && !in_queue[i] && p[i].remaining_time>0)
                    {
                        q.push(i);
                        in_queue[i]=true;
                    }
                    
                }
                q.push(index);
            }
            else
            {
                current_time+=p[index].remaining_time;
                p[index].completion_time=current_time;
                p[index].turnaround_time=p[index].completion_time-p[index].arrival_time;
                p[index].waiting_time=p[index].turnaround_time-p[index].burst_time;
                completed++;
            }
        }
        else
        {
            current_time++;
        }
    }
}
void display(vector<round_robin> &p, int n)
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
int main(){
    int n,quantam;
    cin>>n>>quantam;
    vector<round_robin> p(n);
    for(int i=0;i<n;i++)
    {
        p[i].id=i+1;
        cin>>p[i].arrival_time>>p[i].burst_time;
    }
    roundrobin(p,n,quantam);
    display(p,n);
    return 0;
}
