#include <stdio.h>

// Compile command
// gcc sjf.c

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_by_bt(int *process_no, int *bt, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (bt[i] > bt[j]) {
                swap(&bt[i], &bt[j]);
                swap(&process_no[i], &process_no[j]);
            }
        }
    }
}

void calculate_wt_and_tat(int *bt, int *wt, int *tat, int n, float *avg_wt,
                          float *avg_tat) {
    // calculation is exactly same as fcfs after the sorting
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
    // The difference from the fcfs is just that we are taking the input from
    // the user and we are sorting. Everything else is same as fcfs.
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int bt[n], process_no[n];
    printf("Enter burst time for %d processes:\n", n);
    for (int i = 0; i < n; ++i) {
        process_no[i] = i + 1;
        printf("p%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Sort by the burst time, since in sjf shortest process with shortest bt is
    // executed first
    sort_by_bt(process_no, bt, n);

    int wt[n], tat[n];
    float avg_wt, avg_tat;
    calculate_wt_and_tat(bt, wt, tat, n, &avg_wt, &avg_tat);

    printf("Processes\tBurst time\tWating time\tTurn around time\n");
    for (int i = 0; i < n; ++i)
        printf("%d\t\t%d\t\t%d\t\t%d\n", (i + 1), bt[i], wt[i], tat[i]);

    printf("Average waiting time = %f\n", avg_wt);
    printf("Average turn around time = %f\n", avg_tat);
}
