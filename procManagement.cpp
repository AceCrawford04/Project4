//procManagement implementaion. 

#include "procManagement.h"

void ProcessQueues::moveToReady(const Process& p) {
    readyQueue.push(p);
}

void ProcessQueues::moveToWaiting(const Process& p) {
    waitingQueue.push(p);
}

void ProcessQueues::moveToTerminated(const Process& p) {
    terminatedQueue.push(p);
}

Process ProcessQueues::popFromReady() {
    if (readyQueue.empty()) {
        perror("Attempted to pop from an empty ready queue");
    }
    Process frontProc = readyQueue.front();
    readyQueue.pop();
    return frontProc;
}

Process ProcessQueues::popFromWaiting() {
    if (waitingQueue.empty()) {
        perror("Empty queue, can not pop."); 
    }
    Process frontProc = waitingQueue.front();
    waitingQueue.pop();
    return frontProc;
}

bool ProcessQueues::isReadyEmpty() const {
    return readyQueue.empty();
}

bool ProcessQueues::isWaitingEmpty() const {
    return waitingQueue.empty();
}
