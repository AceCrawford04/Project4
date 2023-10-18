// procManagement.h

#ifndef PROC_MANAGEMENT_H
#define PROC_MANAGEMENT_H

#include <string>
#include <queue>

using namespace std;

class Process {
public:
    string ID;
    int Arrival_Time;
    int Total_CPU_Burst;
    int Priority;

    Process(string id, int arrival, int burst, int priority)
        : ID(id), Arrival_Time(arrival), Total_CPU_Burst(burst), Priority(priority) {}
};

class ProcessQueues {
private:
    queue<Process> waitingQueue;
    queue<Process> readyQueue;
    queue<Process> terminatedQueue;
public:
    void moveToReady(const Process& p);
    void moveToWaiting(const Process& p);
    void moveToTerminated(const Process& p);

}; 


#endif 