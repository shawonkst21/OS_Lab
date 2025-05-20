#include <bits/stdc++.h>
using namespace std;

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int priority;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

void preemptivePriorityScheduling(vector<Process>& p, int n) {
    vector<int> remaining_time(n);
    for (int i = 0; i < n; i++) {
        remaining_time[i] = p[i].burst_time;
    }

    int current_time = 0, completed = 0;
    vector<bool> is_completed(n, false);

    while (completed < n) {
        int idx = -1;
        int highest_priority = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (p[i].arrival_time <= current_time && !is_completed[i]) {
                if (remaining_time[i] > 0 && p[i].priority < highest_priority) {
                    highest_priority = p[i].priority;
                    idx = i;
                } else if (p[i].priority == highest_priority && remaining_time[i] > 0) {
                    
                    if (p[i].arrival_time < p[idx].arrival_time) {
                        idx = i;
                    }
                }
            }
        }

        if (idx != -1) {
            remaining_time[idx]--;
            current_time++;

            if (remaining_time[idx] == 0) {
                p[idx].completion_time = current_time;
                p[idx].turnaround_time = p[idx].completion_time - p[idx].arrival_time;
                p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;
                is_completed[idx] = true;
                completed++;
            }
        } else {
            current_time++;
        }
    }
}

void display(const vector<Process>& p, int n) {
    cout << "ID\tArrival\tBurst\tPriority\tCompletion\tTurnaround\tWaiting\n";
    for (int i = 0; i < n; i++) {
        cout << p[i].id << "\t"
             << p[i].arrival_time << "\t"
             << p[i].burst_time << "\t"
             << p[i].priority << "\t\t"
             << p[i].completion_time << "\t\t"
             << p[i].turnaround_time << "\t\t"
             << p[i].waiting_time << "\n";
    }
}

int main() {
    int n;
    cin >> n;

    vector<Process> p(n);
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        cin >> p[i].arrival_time >> p[i].burst_time >> p[i].priority;
    }

    preemptivePriorityScheduling(p, n);
    display(p, n);

    return 0;
}
