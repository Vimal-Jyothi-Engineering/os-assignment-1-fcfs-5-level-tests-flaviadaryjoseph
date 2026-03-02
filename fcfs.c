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
    struct Process p[100];
    int n = 0;

    // Read until EOF
    while (scanf("%s %d %d", p[n].pid, &p[n].arrival, &p[n].burst) == 3) {
        n++;
    }

    // Sort by arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].arrival > p[j].arrival) {
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    int current_time = 0;
    for (int i = 0; i < n; i++) {
        if (current_time < p[i].arrival) current_time = p[i].arrival;

        p[i].waiting = current_time - p[i].arrival;
        p[i].turnaround = p[i].waiting + p[i].burst;

        current_time += p[i].burst;

        printf("%s %d %d\n", p[i].pid, p[i].waiting, p[i].turnaround);
    }

    return 0;
}