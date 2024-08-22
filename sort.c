#include <stdio.h>
#include <stdbool.h>

bool check_sort(int *arr, size_t size);
// void printArray(int arr[], int size);

int main() {
    int arr[] = {78, 12, 1, 9, 7, 2, 10, 11, 11, 57, 62, 15, 8, 34, 67, 89, 54, 23, 13, 109};
    size_t array_size = sizeof arr / sizeof arr[0];
    
    // printf("%d", check_sort(arr, array_size));
    while (check_sort(arr, array_size) == false) {
        // printArray(arr, array_size);
        for (int i = 0; i < array_size-1; i++) {
                if (arr[i] < arr[i+1]) {
                arr[i] = arr[i];
                } else {
                    int temp = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = temp;
                }
        }
    }
    for (int i = 0; i < sizeof arr / sizeof arr[0]; i++) {
        printf("\n%d", arr[i]);
    }
}

bool check_sort(int *arr, size_t size) {
    bool bool_arr[size-1];
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

// void printArray(int arr[], int size) {
//     printf("[");
//     for (int i = 0; i < size; i++) {
//         printf("%d", arr[i]);
//         if (i < size - 1) {
//             printf(", ");  // Add a comma and space between elements
//         }
//     }
//     printf("]\n");
// }
