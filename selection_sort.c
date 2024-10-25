#include <stdio.h>
// Using the swap approach

int main() {
    int arr[] = {5, 6, 1, 2, 7, 3, 9};
    int minVal = arr[0];

    printf("\n");
    for (int j = 0; j < sizeof(arr)/sizeof(*arr); j++) {
        printf("%d ", arr[j]);
    }

    // Loop through items in array
    for (int i = 0; i < sizeof(arr)/sizeof(*arr) - 1; i++) {
        // Loop through items in array starting from the current index of the outer loop
        for (int j = i; j < sizeof(arr)/sizeof(*arr); j++) {
            // This loop find the minimum value at a specified range in the array
            if (arr[j] < minVal) minVal = arr[j];
        }
        
        // Swap the values
        for (int j = i; j < sizeof(arr)/sizeof(*arr); j++) {
            if (arr[j] == minVal) {
                arr[j] = arr[i];
                arr[i] = minVal;
                minVal = arr[i+1];
                break;
            }
        }

        printf("\n");
        for (int j = 0; j < sizeof(arr)/sizeof(*arr); j++) {
            printf("%d ", arr[j]);
        }
    }
    
    return 0;
}