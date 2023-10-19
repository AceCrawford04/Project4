// implementation file for SJF. 

#include "SJF.h"
#include <iostream>
#include <fstream>

using namespace std; 

SJF::SJF() {
    // Any initialization for FCFS can go here
}

int SJF::loadProcessesFromFile(const string& fileName) {
    ifstream inFile(fileName);
    int processCount;

    if (!inFile.is_open()) {
        cout << "Error: Could not open file " << fileName << endl;
        return 0;
    }
    string id;
    int arrival, burst, priority;
    //while (inFile >> id >> arrival >> burst >> priority) {
    //With the original while loop, it never actaully executed the code in the body during my testing, however it does print put 4 random numbers before that i cannot track down.
    while (inFile) {
        cout << id << " " << arrival << " " << burst << " " << priority << endl;
        Process newProcess(id, arrival, burst, priority);
        readyQueue.push(newProcess);
        cout << id << " " << arrival << endl;
         inFile >> id >> arrival >> burst >> priority;
         processCount++;
    }
    return processCount;
}


void SJF::execute(bool verbose, int processCount) {
    //cout << "this is" << verbose << endl;
    int currentTime = 0;  // Keep track of current time
    double totalWaitTime = 0;  // Accumulator for total waiting time

    while (!readyQueue.empty()) {
        Process current = readyQueue.front();
        readyQueue.pop();

         //Calculate wait time for this process
        int waitTime = currentTime - current.Arrival_Time;
        totalWaitTime += waitTime;

        // Verbose output
        if (verbose) {
            cout << "Time " << currentTime << ": Processing " << current.ID << endl;
        }

        // Simulate processing...
        currentTime += current.Total_CPU_Burst;  // Add burst time to current time
    }
cout << "total wait time: " << totalWaitTime << endl;
cout << "current time: " << currentTime << endl;
cout << "number of processes: 5" << processCount << endl;
    averageWaitTime = totalWaitTime / processCount;
    cout << "Average Wait Time: " << averageWaitTime << endl;
}
