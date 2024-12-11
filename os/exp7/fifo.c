#include <stdio.h>

// Compile command
// gcc fifo.c

int find_page_in_frame(int *frames, int n, int page) {
    // return the index of frame, if not found return -1
    for (int i = 0; i < n; ++i)
        if (frames[i] == page) return i;
    return -1;
}

int main() {
    int instream[] = {4, 1, 2, 4, 5};
    int page_faults = 0;
    int frames[3] = {-1, -1, -1};
    int no_frames = 3;
    int no_pages = sizeof(instream) / sizeof(instream[0]);
    int index = 0;  // Keep track of the next frame to be replaced

    printf("Incoming\tFrame 1\tFrame 2\tFrame 3\n");
    for (int i = 0; i < no_pages; ++i) {
        if (find_page_in_frame(frames, no_frames, instream[i]) == -1) {
            ++page_faults;
            // Replace the frame with new page
            frames[index] = instream[i];
            // Look at the manually solved examples. It is just going till the
            // last frame and then again starting from the first frame.
            index = (index + 1) % no_frames;
        }

        printf("%d\t\t", instream[i]);
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
