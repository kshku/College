#include <stdio.h>

// Compile command
// gcc priority.c

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_by_priority(int *process_no, int *bt, int *priority, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (priority[i] > priority[j]) {
                swap(&priority[i], &priority[j]);
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
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int process_no[n], bt[n], priority[n];
    for (int i = 0; i < n; ++i) {
        printf("Enter the process number: ");
        scanf("%d", &process_no[i]);
        printf("Enter the burst time: ");
        scanf("%d", &bt[i]);
        printf("Enter the priority: ");
        scanf("%d", &priority[i]);
    }

    // Here similar to sjf, but we are going to sort based on the priority.
    sort_by_priority(process_no, bt, priority, n);

    int wt[n], tat[n];
    float avg_wt, avg_tat;
    calculate_wt_and_tat(bt, wt, tat, n, &avg_wt, &avg_tat);

    printf("Processes\tBurst time\tPriority\tWating time\tTurn around time\n");
    for (int i = 0; i < n; ++i)
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", process_no[i], bt[i],
               priority[i], wt[i], tat[i]);

    printf("Average waiting time = %f\n", avg_wt);
    printf("Average turn around time = %f\n", avg_tat);
}
