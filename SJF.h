// header file for SJF.

#ifndef SJF_H
#define SJF_H

#include "procManagement.h"
#include <vector>

class SJF {
public:
    SJF();  // Constructor
    int loadProcessesFromFile(const string& fileName);  // Load processes from a file
    void execute(bool verbose = false, int processCount = 1);  // Executes the SJF scheduling

private:
    queue<Process> readyQueue;  // Queue of ready processes
    double averageWaitTime = 0;  // To calculate average wait time

    // other methods can go here
};

#endif // SJF_H
