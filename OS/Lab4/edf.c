#include <stdio.h>

typedef struct {
    int id;
    int arrival_time;
    int execution_time;
    int deadline;
} Task;

void sortTasks(Task tasks[], int num_tasks) {
    int i, j;
    Task temp;

    for (i = 0; i < num_tasks - 1; i++) {
        for (j = i + 1; j < num_tasks; j++) {
            if (tasks[j].deadline < tasks[i].deadline) {
                temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
}

void scheduleTasks(Task tasks[], int num_tasks) {
    int current_time = 0;
    int i, is_completed = 0;

    printf("Task\tArrival\tExecution\tDeadline\n");

    for (i = 0; i < num_tasks; i++) {
        printf("%d\t%d\t%d\t\t%d\n", tasks[i].id, tasks[i].arrival_time, tasks[i].execution_time, tasks[i].deadline);
    }

    printf("\n");

    while (!is_completed) {
        int earliest_deadline_task = -1;
        int earliest_deadline = -1;

        for (i = 0; i < num_tasks; i++) {
            if (tasks[i].arrival_time <= current_time && tasks[i].execution_time > 0) {
                if (earliest_deadline_task == -1 || tasks[i].deadline < earliest_deadline) {
                    earliest_deadline_task = i;
                    earliest_deadline = tasks[i].deadline;
                }
            }
        }

        if (earliest_deadline_task == -1) {
            current_time++;
            continue;
        }

        // Execute the task for one time unit
        tasks[earliest_deadline_task].execution_time--;
        printf("Executing task %d at time %d\n", tasks[earliest_deadline_task].id, current_time);

        // Increment current time
        current_time++;

        // Check if the task is completed
        if (tasks[earliest_deadline_task].execution_time == 0) {
            printf("Task %d completed at time %d\n", tasks[earliest_deadline_task].id, current_time);
        }

        // Check if all tasks are completed
        is_completed = 1;
        for (i = 0; i < num_tasks; i++) {
            if (tasks[i].execution_time > 0) {
                is_completed = 0;
                break;
            }
        }
    }
}

int main() {
    // Create an array of tasks
    Task tasks[] = {
        {1, 0, 5, 10},
        {2, 2, 3, 7},
        {3, 4, 4, 12},
        {4, 6, 2, 9}
    };

    int num_tasks = sizeof(tasks) / sizeof(tasks[0]);

    // Sort tasks based on earliest deadline
    sortTasks(tasks, num_tasks);

    // Perform EDF scheduling
    scheduleTasks(tasks, num_tasks);

    return 0;
}
