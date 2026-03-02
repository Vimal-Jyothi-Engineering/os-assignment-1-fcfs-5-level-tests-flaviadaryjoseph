#include <stdio.h>
#include <string.h>

struct Process {
    char pid[10];
    int arrival;
    int burst;
    int waiting;
    int turnaround;
};

int main() {
    int n;
    scanf("%d", &n);

    struct Process p[n];

    for(int i = 0; i < n; i++) {
        scanf("%s %d %d", p[i].pid, &p[i].arrival, &p[i].burst);
    }

    // SORT by arrival time (FCFS rule)
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(p[i].arrival > p[j].arrival) {
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    int current_time = 0;
    float total_waiting = 0;
    float total_turnaround = 0;

    for(int i = 0; i < n; i++) {

        // If CPU is idle
        if(current_time < p[i].arrival) {
            current_time = p[i].arrival;
        }

        p[i].waiting = current_time - p[i].arrival;
        current_time += p[i].burst;
        p[i].turnaround = p[i].waiting + p[i].burst;

        total_waiting += p[i].waiting;
        total_turnaround += p[i].turnaround;
    }

    printf("Waiting Time:\n");
    for(int i = 0; i < n; i++) {
        printf("%s %d\n", p[i].pid, p[i].waiting);
    }

    printf("Turnaround Time:\n");
    for(int i = 0; i < n; i++) {
        printf("%s %d\n", p[i].pid, p[i].turnaround);
    }

    printf("Average Waiting Time: %.2f\n", total_waiting / n);
    printf("Average Turnaround Time: %.2f", total_turnaround / n);

    return 0;
}