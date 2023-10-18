// implementation file for FCFS. 

#include "FCFS.h"
#include <iostream>
#include <fstream>

using namespace std; 

FCFS::FCFS() {
    // Any initialization for FCFS can go here
}

void FCFS::loadProcessesFromFile(const string& fileName) {
    ifstream inFile(fileName);

    if (!inFile.is_open()) {
        cout << "Error: Could not open file " << fileName << endl;
        return;
    }

    string id;
    int arrival, burst, priority;
    while (inFile >> id >> arrival >> burst >> priority) {
        Process newProcess(id, arrival, burst, priority);
        readyQueue.push(newProcess);
    }
}

void FCFS::execute(bool verbose) {
    int currentTime = 0;  // Keep track of current time
    double totalWaitTime = 0;  // Accumulator for total waiting time

    while (!readyQueue.empty()) {
        Process current = readyQueue.front();
        readyQueue.pop();

        // Calculate wait time for this process
        int waitTime = currentTime - current.Arrival_Time;
        totalWaitTime += waitTime;

        // Verbose output
        if (verbose) {
            cout << "Time " << currentTime << ": Processing " << current.ID << endl;
        }

        // Simulate processing...
        currentTime += current.Total_CPU_Burst;  // Add burst time to current time
    }

    averageWaitTime = totalWaitTime / currentTime;
    cout << "Average Wait Time: " << averageWaitTime << endl;
}





