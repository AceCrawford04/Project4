//File: CPUscheduler.cpp
//Ace Crawford, Cameron Herine, and Theresa Redford 
//Fall 2023, Transy
//Operating Systems
//This is the driver file for our CPU scheduler, (continue description)
//(what works, what does not)

#include "CPUScheduler.h"


int main (int argc, char** argv){

//we can delete these, but I find them helpful for testing
cout << argc << endl;

for (int i=0; i < argc; i++){
			cout << argv[i] << endl;
		
		}
	
cout << endl;

ifstream inFile;

bool FCFS, SJF, Priority, RR;

bool preemtive;

FCFS = true;

preemtive = false;

if(argc == 1){
	cout << "No arguments were passed" << endl;
	}

//I would love if we could figure out how to not have to make these strings
string stringSJF = "--typeSJF";
string stringRR = "--typeRR";
string stringPriority = "--typePriority";
string stringPreemptive = "--preemptive";
for (int i=0; i < argc; i++){
	//tests for type
		if(argv[i] == stringSJF)
{
	FCFS = false;
	SJF = true;
	cout << "type is: --typeSJF" << endl;

}
	else if(argv[i] == stringRR)
{
	FCFS = false;
	RR = true;
	cout << "type is: --typeRR" << endl;

}
	else if(argv[i] == stringPriority)
{
	FCFS = false;
	Priority = true;
	cout << "type is: --typePriority" << endl;

}

//tests for preemptive
	if(argv[i] == stringPreemptive){
		preemtive = false;
		cout << "preemtive" << endl;
	}
}

	

//change file name to variable
inFile.open ("sched.in");

//we can take some/all of this out, but I find it helpful for testing purposes
if (!inFile.is_open()) {
	cout << "Error: sched.in could not be opened" << endl;
}
else {
	cout << "File sucessfully opened!" << endl;
}

}
