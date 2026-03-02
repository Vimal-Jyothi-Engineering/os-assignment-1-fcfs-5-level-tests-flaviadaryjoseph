#include <stdio.h>

typedef struct {
    char pid[20];
    int at;
    int bt;
    int wt;
    int tat;
} Process;

int main() {
    int n;
    scanf("%d", &n);

    Process p[n];

    // Read input
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", p[i].pid, &p[i].at, &p[i].bt);
    }

    // Sort by arrival time (FCFS rule)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].at > p[j + 1].at) {
                Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    // FCFS Calculation (Cumulative Burst Time Method)
    if (n > 0) {
        p[0].wt = 0;
        p[0].tat = p[0].bt;

        for (int i = 1; i < n; i++) {
            p[i].wt = p[i - 1].wt + p[i - 1].bt;
            p[i].tat = p[i].wt + p[i].bt;
        }
    }

    double total_wt = 0, total_tat = 0;

    for (int i = 0; i < n; i++) {
        total_wt += p[i].wt;
        total_tat += p[i].tat;
    }

    double avg_wt = total_wt / n;
    double avg_tat = total_tat / n;

    // Output in EXACT required format
    printf("Waiting Time:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %d\n", p[i].pid, p[i].wt);
    }

    printf("Turnaround Time:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %d\n", p[i].pid, p[i].tat);
    }

    printf("Average Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);

    return 0;
}