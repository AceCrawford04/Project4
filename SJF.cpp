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
    int processCount = 0;
    //string processes[processCount][3];
    //string processes[processCount];

    if (!inFile.is_open()) {
        cout << "Error: Could not open file " << fileName << endl;
        return 0;
    }
    string id;
    int arrival, burst, priority;

    //while (inFile >> id >> arrival >> burst >> priority) {
    //With the original while loop, it never actaully executed the code in the body during my testing, however it does print put 4 random numbers before that i cannot track down.
    inFile >> id >> arrival >> burst >> priority; //Reference (1) (used for this line and in infile inside the while loop)
   while (inFile) { 
        inFile >> id >> arrival >> burst >> priority;
        processCount++;

         cout << "first loop" << processCount << endl; //https://press.rebus.community/programmingfundamentals/chapter/loading-an-array-from-a-text-file/
     }
     //int *ptr;
     putQueue(fileName, processCount);
    // sortQueue(ptr, processCount);
     //string processes[processCount][3];

     //inFile >> id >> arrival >> burst >> priority; //Reference (1) (used for this line and in infile inside the while loop)
 //  while (inFile) {
      // for (int i = 0; i < processCount; i++){
       // cout << " first second loop: " << endl;
          // for (int t = 0; t < 4; t++){
              //  inFile >> processes[i][t];
              //  cout << "second loop: " << processes[i][t] << endl;
       // }
       // }
    // }

        

        
       // processCount++;
        cout << id << " " << arrival << " " << burst << " " << priority << endl;
        //Process newProcess(id, arrival, burst, priority);
        //readyQueue.push(newProcess);
        cout << id << " " << arrival << endl;
         //inFile >> id >> arrival >> burst >> priority;
    //}
    return processCount;
}

void SJF::putQueue(const string& fileName, int processCount) {
    ifstream inFile(fileName);
  string processes[processCount][3];
 int savecount = processCount;
  int savecount2 = savecount;
  //int savecount3 = processCount;
 // int savecount4 = processCount;

string id;
    int arrival, burst, priority;

       for (int i = 0; i < processCount; i++){
        cout << " first second loop: " << endl;
           for (int t = 0; t < 4; t++){
                inFile >> processes[i][t];
               cout << "second loop: " << processes[i][t] << endl;
        }
       }
   cout << "put in data" << endl;
       // int *ptr = processes;
        //sortQueue(ptr, processCount);
        //return ptr;

     

//void SJF::sortQueue()
    
cout << savecount2 << endl;
//for(int x = 0; x < savecount2; x++){
    for(int i = 0; i < 100; i++){
        for(int x = 0; x < savecount2; x++){
            cout << "if burst: " << processes[x][2] << " equals " << i << endl;
        if (stoi(processes[x][2]) == i) {
            cout << "off array ID: " << processes[x][0] << " Arrival time: " << processes[x][1] << " burst: "<< processes[x][2] << " priority: "<< processes[x][3] << endl; 
             Process newProcess(processes[x][0], stoi(processes[x][1]), stoi(processes[x][2]), stoi(processes[x][3]));
        readyQueue.push(newProcess);
       // processes[i][2] = 0;
        }
    }

    }



    //cout << "before print queue" << endl;
     //for (int i = 0; i < savecount2; i++){
       // cout << "  " << endl;
          // for (int t = 0; t < 4; t++){
              //  cout << "sorted Queue: " << processes[i][t] << endl;
      // }
       // cout << endl;
       // }
    }






void SJF::execute(bool verbose, int processCount) {
    cout << "execute" << endl;
    //cout << "this is" << verbose << endl;
    int currentTime = 0;  // Keep track of current time
    double totalWaitTime = 0;  // Accumulator for total waiting time

    while (!readyQueue.empty()) {
        Process current = readyQueue.front();
        readyQueue.pop();
        cout << "off queue ID: " << current.ID << " Arrival time: " << current.Arrival_Time << " burst: "<< current.Total_CPU_Burst << " priority: "<< current.Priority << endl;

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
cout << "number of processes: " << processCount << endl;
    averageWaitTime = currentTime / processCount;
    cout << "Average Wait Time: " << averageWaitTime << endl;
}

//Refernces
//(1)http://www.cs.uky.edu/~paulp/HowToReadFile.html
