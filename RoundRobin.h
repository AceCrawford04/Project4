//File: RoundRobin.h
//Ace Crawford, Cameron Herine, and Theresa Redford 
//Fall 2023, Transy
//Operating Systems
//Interface for RoundRobin



#ifndef ROUNDROBIN_H
#define ROUNDROBIN_H

#include <iostream>
#include <string>
#include <queue>

using namespace std;

Class RoundRobin{

public:

	RoundRobin(void);
	~RoundRobin(void);

	// public member function
// constructor for the Process struct
   RoundRobin::Process(const string& n, int p, int rt) {
    name = n;
    priority = p;
    remainingTime = rt;
    waitTime = 0;
}


// determinePriorityProcesses function goes here
// loadProcessesFromFile function goes here
// print goes here

private:

	// private members

};

#endif
