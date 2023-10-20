//File: RoundRobin.cpp
//Ace Crawford, Cameron Herine, and Theresa Redford 
//Fall 2023, Transy
//Operating Systems
//Implementation for RoundRobin

// refereences: 

// For idea with regards to how to approach working with priority within round robin.
//https://stackoverflow.com/questions/54858509/what-part-does-priority-play-in-round-robin-scheduling

// for how to use queue library: https://www.geeksforgeeks.org/queue-cpp-stl/

// for push and pop: UStack example from DR England ex 11. 


#include <iostream>
// reading from file
#include <fstream>
#include <queue>
#include "RoundRobin.h"

using namespace std;

RoundRobin::RoundRobin() {
    // Any initialization for RR can go here
}

struct Process {
    string name =" ";
   int priority=0;
   int remainingTime=0;
   int waitTime=0;      
};

// function for retrieving from the file
int RoundRobin::loadProcessesFromFile(const string& fileName) {
    ifstream inFile(fileName);
     int processCount=0;
    


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


// this function compares the prioritites of each process.
//if priority >= 50, then we will put it in a high priority queue.
// if priority is < 50, we will put it in a low priority queue.
// later we will use this to add high priority queue processes to the 
// run queue first. 
//  takes the categorized processes and add them to the run queue
// first pushes the high priority to the queue using .push, then the low priority.
void RoundRobin :: determinePriorityProcesses(const Process>& processes, Process>& runQueue, int timeQuantum) {

    priority_queue<Process, Process, ComparePriority> highPriorityQueue;
    priority_queue<Process, Process, ComparePriority> lowPriorityQueue;

    int time = 0;
      int timeQuantum = 10; 
      int queueCount =0;

    
while (queueCount != processes) {
    const Process& process = *queueCount;
    if (process.priority >= 50) {
        highPriorityQueue.push(process);
    } else {
        lowPriorityQueue.push(process);
    }
    ++queueCount; // Move to the next element
}

    while (!runQueue== 0) {
        Process currentProcess = runQueue;
        runQueue.pop();

 // check if the process completes withing the time quanta, if the remainingTime = 0, then the process has finsihed. 

        if (currentProcess.remainingTime <= timeQuantum) {
 
            currentTime = currentTime+ currentProcess.remainingTime;
            currentProcess.remainingTime = 0;
            currentProcess.waitTime = time + (time - currentProcess.remainingTime);
        } 

// when the quantum time expires, we have to add the process back to its ready queue
        else {
            
            time = time + timeQuantum;
            currentProcess.remainingTime = timeQuantum;
            currentProcess.waitTime = time + time;
            runQueue.push(currentProcess);

        }
    }

    return 0;
}


    queue<Process> runQueue;
    determinePriorityProcesses(readyQueue, runQueue, timeQuantum);

 // print the processes and their wait times respectively

   void RoundRobin :: print(void){

while (queueCount != readyQueue) {
    const Process& process = *it;
    cout << "Process name: " << process.name << endl;
    cout << "The average Wait Time is " << (process.waitTime) / process.remainingTime << endl;
    ++queueCount; 
}

}
