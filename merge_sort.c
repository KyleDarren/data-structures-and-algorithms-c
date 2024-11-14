// UNFINISHED

#include <stdio.h>
#include <stdlib.h>

// For debugging purposes
void print_arr(int *arr, int arr_size) {
    for (int i=0; i < arr_size; i++) {
        printf(" %d ", arr[i]);
    }
}

int* merge_sort(int*, int);
int* merge(int*, int*, int, int);

int main() {

    // Creating a dynamic array
    int static_arr[] = {3, 6, 8, 0, 9, 4, 2};
    int arr_size = sizeof(static_arr) / sizeof(*static_arr);
    int *arr = (int*)calloc(arr_size, sizeof(int));
    for (int i=0; i < arr_size; i++) {
        arr[i] = static_arr[i];
    }

    int* result = merge_sort(arr, arr_size);

    print_arr(result, arr_size);

    // // Check array
    // for (int i=0; i < arr_size; i++) {
    //     printf("%d ", arr[i]);
    // }

    return 0;
}

int* merge_sort(int *arr, int arr_size) {
    if (arr_size <= 1) {
        return arr;
    }

    int left_arr_size = arr_size / 2;
    // Make sure that the right_arr size is +1 than the left_arr if the arr_size is odd
    int right_arr_size = arr_size / 2 + ((arr_size % 2 == 0) ? 0 : 1);

    // Left of the array
    int *left_arr = (int*)calloc(left_arr_size, sizeof(int));
    for (int i=0; i < left_arr_size; i++) {
        left_arr[i] = arr[i];
    }
    
    // Right of the array
    int *right_arr = (int*)calloc(right_arr_size, sizeof(int));
    for (int i=0; i < right_arr_size; i++) {
        right_arr[i] = arr[i+left_arr_size];
    }
    
    int* left_arr_sort = merge_sort(left_arr, left_arr_size);
    int* right_arr_sort = merge_sort(right_arr, right_arr_size);

    return merge(left_arr_sort, right_arr_sort, left_arr_size, right_arr_size);

    free(left_arr);
    free(right_arr);

}

int* merge(int* left_arr, int* right_arr, int left_arr_size, int right_arr_size) {
    int *result_arr = (int*)calloc(left_arr_size + right_arr_size, sizeof(int));

    // Copy left_arr to the result_arr
    for (int i=0; i < left_arr_size; i++) {
        result_arr[i] = left_arr[i];
    }

    // FIX THIS
    // for (int i=0; right_arr_size > 0; i++) {
    //     // If rigt_arr[i] is less than result_arr[i]
    //     if (right_arr[i] < result_arr[i]) {
    //         for (int j=left_arr_size+i; j > 0; j--) {
    //             result_arr[j] = result_arr[j-1];
    //         }
    //         result_arr[0] = right_arr[i];
    //     }
    //     // result_arr[left_arr_size+i] = right_arr[i];
    //     right_arr_size--;
    // }

    return result_arr;

}