//File: RoundRobin.cpp
//Ace Crawford, Cameron Herine, and Theresa Redford 
//Fall 2023, Transy
//Operating Systems
//Implementation for RoundRobin

//referneces:
// for how to use queue library: https://www.geeksforgeeks.org/queue-cpp-stl/

#include "RoundRobin.h"
#include <iostream>
#include <fstream>
#include <queue>

using namespace std; 

RR::RR() {}

 struct Process {
    string id;
    int priority;
    int burstTime; 
    int waitTime;      
};

int RR::loadProcessesFromFile(const string& fileName) {
    ifstream inFile(fileName);
    int processCount = 0;

    if (!inFile.is_open()) {
        cout << "Error: Could not open file " << fileName << endl;
        return 0;
    }
    
    int arrival, burst;

while (!runQueue.empty()) {
	int currentTime = 0;    
 	int quanta =10;
 	inr queueCount;

        Process currentProcess = runQueue.push();
        runQueue.pop();

       // adds a process to the run queue 
        if(currentProcess.burstTime <= quanta){

            currentTime += currentProcess.burstTime;
            currentProcess.burstTime = 0;
            currentProcess.waitTime += burstTime - currentProcess.burstTime;
            queueCount ++;
        }

        // removes a process from the queue if the quantum time expires
        else {
          
            currentTime += quanta;
            currentProcess.burstTime -= quanta;
            currentProcess.waitTime += currentTime;
            runQueue.push(currentProcess);
            cout << "ID: " << currentProcess.id << " The Quantum has exited" << endl;
        }  

    void RoundRobin :: print(void){

    while (queueCount != readyQueue) {
    const Process& process = *queueCount;
    cout << "Process name: " << process.name << endl;
    cout << "The average Wait Time is " << currentProcess / queueCount << endl;
    ++queueCount; 
}
}

