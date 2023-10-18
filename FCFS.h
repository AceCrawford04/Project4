// header file for FCFS.

#ifndef FCFS_H
#define FCFS_H

#include "procManagement.h"
#include <vector>

class FCFS {
public:
    FCFS();  // Constructor
    void loadProcessesFromFile(const string& fileName);  // Load processes from a file
    void execute(bool verbose = false);  // Executes the FCFS scheduling

private:
    queue<Process> readyQueue;  // Queue of ready processes
    double averageWaitTime = 0;  // To calculate average wait time

    // other methods can go here
};

#endif // FCFS_H
