#include <stdio.h>
#include <stdbool.h>

bool check_sort(int *arr, size_t size);

int main() {

    // Sample array
    int arr[] = {78, 12, 1, 9, 7, 2, 10, 11, 11, 57, 62, 15, 8, 34, 67, 89, 54, 23, 13, 109};

    // Array length
    size_t array_size = sizeof arr / sizeof arr[0];
    
    // Check if the array is still not sorted
    while (check_sort(arr, array_size) == false) {

        // Loop through the array but reduce the array size to 1
        // To avoid accessing a garbage data at the end of the array
        for (int i = 0; i < array_size-1; i++) {
            // Check if the current item is greater than the item to its right
            // If does, switch there position
            if (arr[i] > arr[i+1]) {
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            } else {
                arr[i] = arr[i];
            }
            for (int j = 0; j < sizeof arr / sizeof arr[0]; j++) {
                printf(" %d", arr[j]);
            }
            printf("\n");
        }
        
    }
    
}

// This use to check if the array is already sorted
bool check_sort(int *arr, size_t size) {
    bool bool_arr[size - 1];
    bool is_sorted = true;
    for (int i = 0; i < size-1; i++) {
        if (arr[i] <= arr[i+1]) {
            bool_arr[i] = true;
        } else {
            bool_arr[i] = false;
        }
    }
    for (int i = 0; i < sizeof bool_arr / sizeof bool_arr[0]; i++) {
        if (bool_arr[i] == 0) {
            is_sorted = false;
        }
    }
    return is_sorted;
}