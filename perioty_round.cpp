#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Process {
    int pid;        // Process ID
    int bt;         // CPU Burst time required
    int priority;   // Priority of this process
    int remaining_bt; // Remaining burst time for preemptive scheduling
};

// Comparison function for priority queue
struct ComparePriority {
    bool operator()(Process const& p1, Process const& p2) {
        // Higher priority value implies lower priority
        return p1.priority > p2.priority;
    }
};

// Round Robin Scheduling
void roundRobinScheduling(vector<Process>& processes, int quantum) {
    int n = processes.size();
    queue<Process> readyQueue;
    int currentTime = 0;
    int totalTime = 0;

    // Push processes to ready queue
    for (int i = 0; i < n; ++i) {
        processes[i].remaining_bt = processes[i].bt;
        totalTime += processes[i].bt;
    }

    int idx = 0;
    while (currentTime < totalTime) {
        while (idx < n && processes[idx].bt <= currentTime)
            readyQueue.push(processes[idx++]);

        if (!readyQueue.empty()) {
            Process currentProcess = readyQueue.front();
            readyQueue.pop();
            int executionTime = min(quantum, currentProcess.remaining_bt);
            currentTime += executionTime;
            currentProcess.remaining_bt -= executionTime;
            cout << "Executing process " << currentProcess.pid << " for time " << executionTime << endl;
            if (currentProcess.remaining_bt > 0)
                readyQueue.push(currentProcess);
        } else {
            currentTime++;
        }
    }
}

// Preemptive Priority Scheduling
void priorityScheduling(vector<Process>& processes) {
    int n = processes.size();
    priority_queue<Process, vector<Process>, ComparePriority> readyQueue;
    int currentTime = 0;
    int totalTime = 0;
    int totalWaitingTime = 0;

    // Push processes to ready queue
    for (int i = 0; i < n; ++i) {
        processes[i].remaining_bt = processes[i].bt;
        totalTime += processes[i].bt;
    }

    int idx = 0;
    while (currentTime < totalTime) {
        while (idx < n && processes[idx].bt <= currentTime)
            readyQueue.push(processes[idx++]);

        if (!readyQueue.empty()) {
            Process currentProcess = readyQueue.top();
            readyQueue.pop();
            int executionTime = min(1, currentProcess.remaining_bt);
            currentTime += executionTime;
            currentProcess.remaining_bt -= executionTime;
            if (currentProcess.remaining_bt > 0)
                readyQueue.push(currentProcess);
            else
                totalWaitingTime += currentTime - currentProcess.bt;
        } else {
            currentTime++;
        }
    }

    double averageWaitingTime = (double)totalWaitingTime / n;
    cout << "Average waiting time for Priority Scheduling: " << averageWaitingTime << endl;
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    cout << "Enter details for each process:\n";
    for (int i = 0; i < n; ++i) {
        processes[i].pid = i + 1;
        cout << "Process " << processes[i].pid << " Burst time: ";
        cin >> processes[i].bt;
        cout << "Priority: ";
        cin >> processes[i].priority;
    }

    int quantum;
    cout << "Enter the time quantum for Round Robin Scheduling: ";
    cin >> quantum;

    roundRobinScheduling(processes, quantum);
    priorityScheduling(processes);

    return 0;
}
