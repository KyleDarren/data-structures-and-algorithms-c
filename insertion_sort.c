#include <stdio.h>

int main() {
    int arr[] = {9, 7, 6, 15, 17, 5, 10, 11};
    int arr_size = sizeof arr / sizeof *arr;

    for (int i=0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }

    // Loop through each items in the array
    for (int i=1; i < arr_size; i++) {
        // Loop through each item in the left of the current index
        for (int j=0; j < i; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        printf("\n");
        for (int j=0; j < arr_size; j++) {
            printf("%d ", arr[j]);
        }
    }
    return 0;
}