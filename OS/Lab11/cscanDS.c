#include <stdio.h>

// Function to perform bubble sort on an array
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                // Swap arr[i] and arr[j]
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


int main() {
    int n;
    printf("Enter the number of tracks to be traversed: ");
    scanf("%d", &n);

    int tracks[n];

    printf("Enter the tracks: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &tracks[i]);
    }

    int head;
    printf("Enter the header position: ");
    scanf("%d", &head);

    int range;
    printf("Enter the total range: ");
    scanf("%d", &range);

    int lower[n];
    int count = 0;

    // Find the tracks lower than the head position
    for (int i = 0; i < n; i++) {
        if (tracks[i] < head) {
            lower[count] = tracks[i];
            count++;
        }
    }

    bubbleSort(lower, count);

    int total_movement = 0;
    
    // If there are tracks lower than the head
    if (count > 0) {
        total_movement = (range - 1 - head) + (lower[count-1]) + (range - 1);
    } else {
        // If no lower tracks, the head moves to the end and jumps back to the beginning
        total_movement = range - 1 - head + range - 1;
    }

    printf("Total movement is: %d\n", total_movement);

    return 0;
}
