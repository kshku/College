#include <stdio.h>

// Compile command
// gcc lru.c

int find_page_in_frame(int *frames, int n, int page) {
    // If the page is already in frame, no page fault
    for (int i = 0; i < n; ++i)
        if (frames[i] == page) return i;
    return -1;
}

int index_of_lru_frame(int *time, int n) {
    // Find the least number in the time
    // Keep track of the index of least time
    int least = 0;
    for (int i = 0; i < n; ++i)
        if (time[least] > time[i]) least = i;
    return least;
}

int main() {
    int no_frames;
    printf("Enter the number of frames: ");
    scanf("%d", &no_frames);

    // initialize frames and time
    int frames[no_frames], time[no_frames];
    for (int i = 0; i < no_frames; ++i) {
        frames[i] = -1;
        time[i] = -1;
    }

    int no_pages;
    printf("Enter the number of pages: ");
    scanf("%d", &no_pages);

    int pages[no_pages];
    printf("Enter the reference string: ");
    for (int i = 0; i < no_pages; ++i) scanf("%d", &pages[i]);

    printf("Incoming\tFrames\n");

    // Keep track of current time
    int current_time = 0;
    int page_faults = 0;
    for (int i = 0; i < no_pages; ++i, ++current_time) {
        int index = find_page_in_frame(frames, no_frames, pages[i]);
        if (index == -1) {  // page fault
            // Get index of frame to be updated
            index = index_of_lru_frame(time, no_frames);
            frames[index] = pages[i];
            ++page_faults;
        }
        // Update the time for the used frames
        time[index] = current_time;

        printf("%d\t\t", pages[i]);
        for (int i = 0; i < no_frames; ++i) {
            if (frames[i] == -1)
                printf("-\t\t");
            else
                printf("%d\t\t", frames[i]);
        }
        printf("\n");
    }
    printf("Total page faults: %d\n", page_faults);
}
