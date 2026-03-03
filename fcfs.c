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

    struct Process p[100];

    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", p[i].pid, &p[i].arrival, &p[i].burst);
    }

    // Sort by arrival time (stable FCFS)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].arrival > p[j + 1].arrival) {
                struct Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    int current_time = 0;
    float total_wait = 0;
    float total_tat = 0;

    for (int i = 0; i < n; i++) {

        if (current_time < p[i].arrival) {
            current_time = p[i].arrival;
        }

        p[i].waiting = current_time - p[i].arrival;
        current_time += p[i].burst;
        p[i].turnaround = p[i].waiting + p[i].burst;

        total_wait += p[i].waiting;
        total_tat += p[i].turnaround;
    }

    printf("Waiting Time:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %d\n", p[i].pid, p[i].waiting);
    }

    printf("Turnaround Time:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %d\n", p[i].pid, p[i].turnaround);
    }

    printf("Average Waiting Time: %.2f\n", total_wait / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);

    return 0;
}