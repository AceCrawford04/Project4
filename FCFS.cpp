#include "FCFS.h"
#include <iostream>
#include <fstream>
#include <algorithm>  // for built-in sort
#include <queue>     // for built-in queue

using namespace std;

const int MAX_PROCESSES = 10;

FCFS::FCFS() : numberOfProcesses(0), averageWaitTime(0.0) {  // added initialization list
}

void FCFS::loadProcessesFromFile(const string& fileName) {
    ifstream inFile(fileName);

    if (!inFile.is_open()) {
        perror("Could not open file.");
        std::cout << endl;
        return;
    }

    Process processesArray[MAX_PROCESSES];
    int index = 0;

    string id;
    int arrival, burst, priority;
    while (inFile >> id >> arrival >> burst >> priority && index < MAX_PROCESSES) {
        processesArray[index] = Process(id, arrival, burst, priority);
        index++;
    }

    if (index > MAX_PROCESSES) {
        perror("Cannot load processes.");
        return;
    }

    // Sort the array based on Arrival_Time (primary) and ID (secondary, in case of ties)
    sort(processesArray, processesArray + index, [](const Process& a, const Process& b) {
        if (a.Arrival_Time == b.Arrival_Time) {
            return a.ID < b.ID;
        }
        return a.Arrival_Time < b.Arrival_Time;
    });

    // Push the sorted processes to the ready queue
    for (int i = 0; i < index; i++) {
        readyQueue.push(processesArray[i]);
    }

    numberOfProcesses = index;
}

void FCFS::execute(bool verbose) {
    int currentTime = 0;  
    double totalWaitTime = 0;  

    while (!readyQueue.empty()) {
        Process current = readyQueue.front();
        readyQueue.pop();

        // If the current process arrives after the current time, update the time.
        if (current.Arrival_Time > currentTime) {
            currentTime = current.Arrival_Time;
        }

        int waitTime = currentTime - current.Arrival_Time; 
        totalWaitTime += waitTime; 

        // Verbose output
        if (verbose) {
            cout << "Time " << currentTime << ": Processing " << current.ID << endl;
        }

        // Add the CPU Burst time of the current process to the currentTime
        currentTime += current.Total_CPU_Burst;
    }

    averageWaitTime = totalWaitTime / numberOfProcesses; 
    cout << "Average Wait Time: " << averageWaitTime << endl;
}

















