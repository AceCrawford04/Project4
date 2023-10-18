project4: FCFS.o CPUScheduler.o RoundRobin.o Priority.o SJF.o
	g++ FCFS.o CPUScheduler.o RoundRobin.o Priority.o SJF.o -o project4

FCFS: FCFS.cpp FCFS.h 
	g++ -c FCFS.cpp -o FCFS.o

RoundRobin: RoundRobin.cpp RoundRobin.h 
	g++ -c RoundRobin.cpp -o RoundRobin.o

Priority: Priority.cpp Priority.h 
	g++ -c Priority.cpp -o Priority.o

SJF: SJF.cpp SJF.h 
	g++ -c SJF.cpp -o SJF.o

CPUScheduler: CPUScheduler.cpp CPUScheduler.h procManagement.h
	g++ -c CPUScheduler.cpp -o CPUScheduler.o
