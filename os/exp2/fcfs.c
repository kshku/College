#include <stdio.h>

// Compile command
// gcc fcfs.c

void calculate_wt_and_tat(int *bt, int *wt, int *tat, int n, float *avg_wt,
                          float *avg_tat) {
    // Look at the Gantt chart
    // waiting time = waiting time of previous process + burst time of previous
    // process.
    // always tat = waiting time + burst time
    // Arraival time is not considered

    wt[0] = 0;       // always
    tat[0] = bt[0];  // bt + 0 = bt

    int total_wt = wt[0];
    int total_tat = tat[0];

    for (int i = 1; i < n; ++i) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];

        total_wt += wt[i];
        total_tat += tat[i];
    }

    *avg_wt = (float)total_wt / n;
    *avg_tat = (float)total_tat / n;
}

int main() {
    // n = number of processes
    int n = 3;
    int bt[] = {10, 5, 8};

    int wt[n], tat[n];
    float avg_wt, avg_tat;
    calculate_wt_and_tat(bt, wt, tat, n, &avg_wt, &avg_tat);

    printf("Processes\tBurst time\tWating time\tTurn around time\n");
    for (int i = 0; i < n; ++i)
        printf("%d\t\t%d\t\t%d\t\t%d\n", (i + 1), bt[i], wt[i], tat[i]);

    printf("Average waiting time = %f\n", avg_wt);
    printf("Average turn around time = %f\n", avg_tat);
}
