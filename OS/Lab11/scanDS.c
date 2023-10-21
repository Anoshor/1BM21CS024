#include <stdio.h>

// Function to perform bubble sort on an array
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
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

    int total_movement;
    if (count > 0) {
        bubbleSort(lower, count);
        total_movement = (range - 1 - head) + (range - lower[0] -1);
    } else {
        total_movement = range - 1 - head;
    }

    printf("Total movement is: %d\n", total_movement);

    return 0;
}
