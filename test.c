#include <stdio.h>
#include <stdlib.h>

// For debugging purposes
void print_arr(int *arr, int arr_size) {
    for (int i=0; i < arr_size; i++) {
        printf(" %d ", arr[i]);
    }
}

int merge(int* left_arr, int* right_arr, int left_arr_size, int right_arr_size) {
    int *result_arr = (int*)calloc(left_arr_size + right_arr_size, sizeof(int));

    // Copy left_arr to the result_arr
    for (int i=0; i < left_arr_size; i++) {
        result_arr[i] = left_arr[i];
    }

    int i = 0;
    while (right_arr_size > 0) {
        result_arr[left_arr_size+i] = right_arr[i];
        i++;
        right_arr_size--;
    }
    print_arr(result_arr, 8);
}

int main() {
    int left_arr[] = {1, 3, 5, 7};
    int right_arr[] = {2, 4, 6, 8};
    int left_arr_size = sizeof(left_arr) / sizeof(left_arr[0]);
    int right_arr_size = sizeof(right_arr) / sizeof(right_arr[0]);

    merge(left_arr, right_arr, left_arr_size, right_arr_size);
    return 0;
}