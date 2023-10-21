//File: RoundRobin.h
//Ace Crawford, Cameron Herine, and Theresa Redford 
//File: RoundRobin.h
//Ace Crawford, Cameron Herine, and Theresa Redford 
//Fall 2023, Transy
//Operating Systems
//Interface for RoundRobin

#ifndef ROUNDROBIN_H
#define ROUNDROBIN_H

#include <iostream>
#include <string>

using namespace std;

Class RoundRobin{

public:

RoundRobin(void);
~RoundRobin(void);
	
// constructor for the Process struct
   RoundRobin::Process(const string& iProcess, int pProcess, int rtProcess) {
    id = iProcess;
    priority = pProcess;
    remainingTime = rtProcess;
    waitTime = 0;
}

int RoundRobin::loadProcessesFromFile(const string& fileName);
void RoundRobin :: print(void);

private:
};

#endif
