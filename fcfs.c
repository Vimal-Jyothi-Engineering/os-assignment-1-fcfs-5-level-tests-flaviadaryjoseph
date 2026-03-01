#include <stdio.h>
#include <string.h>

typedef struct {
    char pid[10];
    int arrival;
    int burst;
    int start;
    int completion;
} Process;

int main() {
    int n;
    scanf("%d", &n);

    Process p[n];

    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", p[i].pid, &p[i].arrival, &p[i].burst);
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].arrival > p[j].arrival) {
                Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    int current_time = 0;

    for (int i = 0; i < n; i++) {

        if (current_time < p[i].arrival)
            current_time = p[i].arrival;

        p[i].start = current_time;
        p[i].completion = current_time + p[i].burst;

        current_time += p[i].burst;
    }
    for (int i = 0; i < n; i++) {
        printf("%s %d %d\n", p[i].pid, p[i].start, p[i].completion);
    }

    return 0;
}