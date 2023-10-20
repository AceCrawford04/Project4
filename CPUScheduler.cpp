//File: CPUscheduler.cpp
//Ace Crawford, Cameron Herine, and Theresa Redford 
//Fall 2023, Transy
//Operating Systems
//This is the driver file for our CPU scheduler, (continue description)
//(what works, what does not)
#include <iostream>
#include <string>
#include <cstring>
//#include <studio.h>
#include <cstring>
#include <fstream>
#include "FCFS.h"
#include "SJF.h"
#include "Priority.h"
#include "RoundRobin.h"

//#include "CPUScheduler.h"
using namespace std;
// Enumeration for Scheduling Types
enum SchedulingType {
    FCFS_TYPE,
    SJF_TYPE,
    RR_TYPE,
    PRIORITY_TYPE
};

int main(int argc, char** argv) {

    // Command-line argument defaults
    SchedulingType scheduling = FCFS_TYPE;
    bool preemptive = false;
    bool verbose = false;
    string fileName = "sched.in";
    int quanta = 10;

    // Loop through arguments and 

    //set flags
    for (int i = 1; i < argc; i++) {
        string arg = argv[i];
        if (arg == "--type") {
            if (i + 1 < argc) { 
                i++;
                string typeArg = argv[i];
                if (typeArg == "SJF") {
                    scheduling = SJF_TYPE;
                } else if (typeArg == "RR") {
                    scheduling = RR_TYPE;
                } else if (typeArg == "Priority") {
                    scheduling = PRIORITY_TYPE;
                } else {
                    scheduling = FCFS_TYPE; 
                }
            }
            //cout << argv[i] << endl;
        } else if (arg == "--preemptive") {
            preemptive = true;
        } else if (arg == "--file" && i + 1 < argc) {
            fileName = argv[++i]; 
        } else if (arg == "--quanta" && i + 1 < argc) {
            quanta = stoi(argv[++i]); // Reference (1). 
        } else if (arg == "--verbose") {
            verbose = true;
        }
    }


    cout << scheduling << endl; //out
    cout << preemptive << endl;
    cout << fileName << endl;
    cout << quanta  << endl;
    cout << verbose << endl;
    cout << "check" << endl;

    // Opening the file 
    ifstream inFile;
    inFile.open(fileName);
    if (!inFile.is_open()) {
        cout << "Error: " << fileName << " could not be opened" << endl;
    } else {
        cout << "File successfully opened!" << endl;
    }
   // cout << "here" << endl;
    //when I had this under case:SJF_type the program would not compile, so I put it here and it worked
    SJF sjfScheduler;
    //RoundRobin rrScheduler;
    Priority priorityScheduler;
    int processCount;
    //cout << "here" << endl;
//cout << scheduling;
    switch (scheduling) {
        case SJF_TYPE:
       // cout << "12" << endl;
            processCount = sjfScheduler.loadProcessesFromFile(fileName, preemptive);
            if (verbose == false)
           sjfScheduler.execute(verbose, processCount, preemptive);
            else
           sjfScheduler.execute(verbose, processCount, preemptive);
           break;
        case RR_TYPE:
           // RR rrScheduler;
           // RR rrScheduler
            // RR stuff
            break;
        case PRIORITY_TYPE:
            processCount = priorityScheduler.loadProcessesFromFile(fileName, preemptive);
             if (verbose == false)
           priorityScheduler.execute(verbose, processCount, preemptive);
            else
           priorityScheduler.execute(verbose, processCount, preemptive);
            break;
        default:  // Now defaults to FCFS
            FCFS fcfsScheduler;
            fcfsScheduler.loadProcessesFromFile(fileName);
            fcfsScheduler.execute(verbose);

            break;
    }

    return 0;
}
