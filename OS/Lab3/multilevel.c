#include <stdio.h>

#define MAX_QUEUE_SIZE 100

int currentTime=0;
// Structure to represent a process
typedef struct {
    int processID;
    int arrivalTime;
    int burstTime;
    int priority; // 0 for system process, 1 for user process
    int completionTime;
    int tat;
    int wt;
} Process;

float avgTAT=0, avgWT=0;
// Function to execute a process
void executeProcess(Process process) {
    // printf("Executing Process %d\n", process.processID);
    // Simulating the execution time of the process
    // for (int i = 1; i <= process.burstTime; i++) {
    //     printf("Process %d: %d/%d\n", process.processID, i, process.burstTime);
    // }
    currentTime+=process.burstTime;
    process.completionTime=currentTime;
    process.tat=process.completionTime-process.arrivalTime;
    process.wt=process.tat-process.burstTime;
    avgTAT+=process.tat;
    avgWT+=process.wt
    printf("Process %d executed\n", process.processID);
    printf("TAT: %d, WT: %d\n", process.tat, process.wt);
}


// Function to perform FCFS scheduling for a queue of processes
void scheduleFCFS(Process queue[], int size) {
    for (int i = 0; i < size; i++) {
        executeProcess(queue[i]);
    }
}

int main() {
    int numProcesses;
    Process processes[MAX_QUEUE_SIZE];

    // Reading the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    // Reading process details
    for (int i = 0; i < numProcesses; i++) {
        printf("Process %d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrivalTime);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burstTime);
        printf("System(0)/User(1): ");
        scanf("%d", &processes[i].priority);
        processes[i].processID = i + 1;
    }

    // Separate system and user processes into different queues
    Process systemQueue[MAX_QUEUE_SIZE];
    int systemQueueSize = 0;
    Process userQueue[MAX_QUEUE_SIZE];
    int userQueueSize = 0;

    for (int i = 0; i < numProcesses; i++) {
        if (processes[i].priority == 0) {
            systemQueue[systemQueueSize++] = processes[i];
        } else {
            userQueue[userQueueSize++] = processes[i];
        }
    }

    // Execute system queue processes first
    printf("System Queue:\n");
    scheduleFCFS(systemQueue, systemQueueSize);

    // Execute user queue processes
    printf("User Queue:\n");
    scheduleFCFS(userQueue, userQueueSize);

    return 0;
}
