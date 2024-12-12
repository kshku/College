#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// void sort_requests(int *requests, int n) {
//     for (int i = 0; i < n; ++i)
//         for (int j = i + 1; j < n; ++j)
//             if (requests[i] > requests[j]) swap(&requests[i], &requests[j]);
// }

int max(int *requests, int n) {
    int m = requests[0];
    for (int i = 0; i < n; ++i)
        if (requests[i] > m) m = requests[i];
    return m;
}

int min(int *requests, int n) {
    int m = requests[0];
    for (int i = 0; i < n; ++i)
        if (requests[i] < m) m = requests[i];
    return m;
}

int move_high(int *requests, int disk_size, int initial) {
    // Going forward first
    int head_movement = (disk_size - initial);  // should go upto disk size
    // Should come back upto initial so multiply 2
    head_movement *= 2;
    // Now going backward
    head_movement += (initial - requests[0]);
    // Thats it
    return head_movement;
}

int move_low(int *requests, int n, int initial) {
    // Going backward first
    int head_movement = initial;  // should go upto 0
    // Should come back upto initial so multiply 2
    head_movement *= 2;
    // Now going forward
    head_movement += (requests[n - 1] - initial);
    // Thats it
    return head_movement;
}

int main() {
    int no_requests;
    printf("Enter the total number of requests: ");
    scanf("%d", &no_requests);

    int requests[no_requests];
    printf("Enter the sequence of requests: ");
    for (int i = 0; i < no_requests; ++i) scanf("%d", &requests[i]);

    int initial_head_pos;
    printf("Enter initial head position: ");
    scanf("%d", &initial_head_pos);

    int disk_size;
    printf("Enter disk size: ");
    scanf("%d", &disk_size);

    int direction;
    printf("Enter head movement direction(0 -> low 1 -> high): ");
    scanf("%d", &direction);

    int low = min(requests, no_requests);
    int high = max(requests, no_requests);

    printf(
        "Total head movement is %d\n",
        (direction == 1)
            ? (((disk_size - initial_head_pos) * 2) + (initial_head_pos - low))
            : (((initial_head_pos) * 2) + high - initial_head_pos));

    // sort_requests(requests, no_requests);

    // printf("Total head movement is %d\n",
    //        (direction == 1)
    //            ? move_high(requests, disk_size, initial_head_pos)
    //            : move_low(requests, no_requests, initial_head_pos));
}
