//File: CPUscheduler.cpp
//Ace Crawford, Cameron Herine, and Theresa Redford 
//Fall 2023, Transy
//Operating Systems
//This is the driver file for our CPU scheduler, (continue description)
//(what works, what does not)

#include "CPUScheduler.h"

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

    // Loop through arguments and set flags
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
        } else if (arg == "--preemptive") {
            preemptive = true;
        } else if (arg == "--file" && i + 1 < argc) {
            fileName = argv[++i]; 
        } else if (arg == "--quanta" && i + 1 < argc) {
            quanta = stoi(argv[++i]); // Referemce (1). 
        } else if (arg == "--verbose") {
            verbose = true;
        }
    }

    // Opening the file 
    ifstream inFile;
    inFile.open(fileName);
    if (!inFile.is_open()) {
        cout << "Error: " << fileName << " could not be opened" << endl;
    } else {
        cout << "File successfully opened!" << endl;
    }

    SJF sjfScheduler;
    int processCount;

    switch (scheduling) {
        case SJF_TYPE:
            processCount = sjfScheduler.loadProcessesFromFile(fileName);
           sjfScheduler.execute(verbose, processCount);
           break;
        case RR_TYPE:
           // RR rrScheduler;
           // RR rrScheduler
            // RR stuff
            break;
        case PRIORITY_TYPE:
            // Priority stuff
            break;
        default:  // Now defaults to FCFS
            FCFS fcfsScheduler;
            fcfsScheduler.loadProcessesFromFile(fileName);
            fcfsScheduler.execute(verbose);
            break;
    }

    return 0;
}

// Reference 1: https://cplusplus.com/reference/string/stoi/
