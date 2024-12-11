#include <stdio.h>

// Compile command
// gcc rr.c

void calculate_wt_and_tat(int *bt, int *wt, int *tat, int time_quantum, int n,
                          float *avg_wt, float *avg_tat) {
    // Look at the Gantt chart

    // let's keep track of current time
    int current_time = 0;

    // Let's copy the bt since we are going to modify it.
    int bt_copy[n];
    // Let's also calculate total bt here itself
    int total_bt = 0;
    for (int i = 0; i < n; ++i) {
        bt_copy[i] = bt[i];
        total_bt += bt[i];
    }

    // To calculate average
    int total_wt = 0, total_tat = 0;

    // We know that in any scheduling algorithm the time won't go beyond the sum
    // of the burst time right?
    while (current_time < total_bt) {
        for (int i = 0; i < n; ++i) {
            // If process completed, continue
            if (bt_copy[i] == 0) continue;
            // If process need time more than qunatum time, process is executed
            // for amount of time mentioned in time_qunatum.
            if (bt_copy[i] > time_quantum) {
                current_time += time_quantum;  // update current time
                // subtract time_quantum from bt_copy, representing the
                // execution for that much amount of time
                bt_copy[i] -= time_quantum;
            } else {  // process need less time that quantum time
                current_time += bt_copy[i];  // update current time
                // After the execution the process should be completed
                bt_copy[i] = 0;
                // NOTE: Arraival time is not considered
                // Basically the current time is the turn around time of the
                // process (observe the Gantt chart carefully) and we know that
                // turn around time = waiting time + burst time
                // NOTE: total burst time not remaining burst time
                wt[i] = current_time - bt[i];
                // since current time is nothing but tat
                tat[i] = current_time;

                total_wt += wt[i];
                total_tat += tat[i];
            }
        }
    }

    *avg_wt = (float)total_wt / n;
    *avg_tat = (float)total_tat / n;
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n];
    for (int i = 0; i < n; ++i) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    int time_quantum;
    printf("Enter time quantum: ");
    scanf("%d", &time_quantum);

    int wt[n], tat[n];
    float avg_wt, avg_tat;
    calculate_wt_and_tat(bt, wt, tat, time_quantum, n, &avg_wt, &avg_tat);

    printf("Process\tBurst time\tWaiting time\tTurn around time\n");
    for (int i = 0; i < n; ++i)
        printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);

    printf("Average waiting time = %f\n", avg_wt);
    printf("Average turn around time = %f\n", avg_tat);
}
