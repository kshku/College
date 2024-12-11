#include <stdbool.h>
#include <stdio.h>

// Compile command
// gcc deadlock.c

// Making these global only to avoid dynamic memory allocation
int allocated[5][3] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};
int max_required[5][3] = {
    {7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};
int resource_instances[3] = {10, 5, 7};
int need[5][3];
// int available[3];
int available[3] = {3, 3, 2};
int sequence[5];
int processes = 5, resources = 3;

void calculate_need() {
    // Need = max_required - allocated
    for (int i = 0; i < processes; ++i)
        for (int j = 0; j < resources; ++j)
            need[i][j] = max_required[i][j] - allocated[i][j];
}

// void calculate_availalbe() {
//     // availabe = sum(allocated resource)
//     // If three resources are there A, B, C
//     // then avail = [sum(allocated A), sum(allocated B), sum(allocated C)]

//     // initialize to resource instances
//     for (int i = 0; i < resources; ++i) available[i] = resource_instances[i];

//     // Subtract allocated from available to calculate available
//     for (int i = 0; i < processes; ++i)      // Loop over processes
//         for (int j = 0; j < resources; ++j)  // Loop over resources
//             available[j] -= allocated[i][j];
// }

bool is_enough(int *need, int *available, int resources) {
    // Return whether need is less than or equal to avail
    for (int i = 0; i < resources; ++i)
        if (need[i] > available[i]) return false;
    return true;
}

bool is_equal(int *available, int *resource_instances, int resources) {
    // Return true if all the correspoding numbers are equal
    for (int i = 0; i < resources; ++i)
        if (resource_instances[i] != available[i]) return false;
    return true;
}

bool findSafeSequence() {
    // Let's keep track of whether the process is completed
    bool completed[processes];
    // initialize to false
    for (int i = 0; i < processes; ++i) completed[i] = false;

    // Keeping track of the next index of the sequence to be appended
    int idx = 0;

    // We know that when we find a safe sequence available = resource
    // instances
    while (!is_equal(available, resource_instances, resources)) {
        // Keep track of whether we are in deadlock are not
        // Let's assume we are in deadlock
        bool deadlock = true;
        for (int i = 0; i < processes; ++i) {  // loop over the resources
            // Check whether not completed and available is enough for
            // allocation for this process.
            if (!completed[i] && is_enough(need[i], available, resources)) {
                // Add this process to the sequence and mark it as completed
                completed[i] = true;
                sequence[idx++] = i;

                // Update the available
                for (int j = 0; j < resources; ++j)
                    available[j] += allocated[i][j];

                // Since we have executed a process we are not in deadlock
                deadlock = false;
            }
        }
        // After looping over all the processes still we haven't executed any
        // process deadlock will be true and there is not safe sequence
        if (deadlock) return false;
    }

    return true;
}

int main() {
    calculate_need(max_required, allocated, need, processes, resources);

    // calculate_availalbe(allocated, resource_instances, available, processes,
    //                     resources);

    if (findSafeSequence(need, available, allocated, resource_instances,
                         sequence, processes, resources)) {
        printf("The safe sequence is: ");
        for (int i = 0; i < processes - 1; ++i) printf("p%d->", sequence[i]);
        printf("p%d\n", sequence[processes - 1]);
    } else {
        printf("The system is not safe\n");
    }
}
