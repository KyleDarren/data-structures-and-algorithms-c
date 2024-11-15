#include <stdio.h>
#include <stdlib.h>

// For debugging purposes
void print_arr(int *arr, int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        printf(" %d ", arr[i]);
    }
    printf("\n");
}

int* merge_sort(int*, int);
int* merge(int*, int*, int, int);
void removeFirst(int **arr, int *arr_size);
void insertBefore(int **arr, int *arr_size, int index, int item);

int main() {
    // Creating a dynamic array
    int static_arr[] = {3, 6, 8, 0, 9, 4, 2};
    int arr_size = sizeof(static_arr) / sizeof(*static_arr);
    int *arr = (int*)malloc(arr_size * sizeof(int));
    if (arr == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < arr_size; i++) {
        arr[i] = static_arr[i];
    }

    int* result = merge_sort(arr, arr_size);

    // Print the sorted array
    print_arr(result, arr_size);

    // Free allocated memory
    free(result);
    free(arr);

    return 0;
}

int* merge_sort(int *arr, int arr_size) {
    if (arr_size <= 1) {
        int *result = (int*)malloc(arr_size * sizeof(int));
        if (result == NULL) {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
        if (arr_size > 0) {
            result[0] = arr[0];
        }
        return result;
    }

    int left_arr_size = arr_size / 2;
    int right_arr_size = arr_size - left_arr_size;

    // Left of the array
    int *left_arr = (int*)malloc(left_arr_size * sizeof(int));
    if (left_arr == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < left_arr_size; i++) {
        left_arr[i] = arr[i];
    }

    // Right of the array
    int *right_arr = (int*)malloc(right_arr_size * sizeof(int));
    if (right_arr == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < right_arr_size; i++) {
        right_arr[i] = arr[i + left_arr_size];
    }

    int* left_arr_sort = merge_sort(left_arr, left_arr_size);
    int* right_arr_sort = merge_sort(right_arr, right_arr_size);

    free(left_arr);
    free(right_arr);

    return merge(left_arr_sort, right_arr_sort, left_arr_size, right_arr_size);
}

int* merge(int* left_arr, int* right_arr, int left_arr_size, int right_arr_size) {
    int *result_arr = (int*)malloc((left_arr_size + right_arr_size) * sizeof(int));
    if (result_arr == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    int i = 0, j = 0, k = 0;

    while (i < left_arr_size && j < right_arr_size) {
        if (left_arr[i] <= right_arr[j]) {
            result_arr[k++] = left_arr[i++];
        } else {
            result_arr[k++] = right_arr[j++];
        }
    }

    // Copy remaining elements from left_arr
    while (i < left_arr_size) {
        result_arr[k++] = left_arr[i++];
    }

    // Copy remaining elements from right_arr
    while (j < right_arr_size) {
        result_arr[k++] = right_arr[j++];
    }

    free(left_arr);
    free(right_arr);

    return result_arr;
}

void removeFirst(int **arr, int *arr_size) {
    if (*arr_size <= 0 || *arr == NULL) {
        return;
    }

    for (int i = 1; i < *arr_size; i++) {
        (*arr)[i - 1] = (*arr)[i];
    }

    int *new_arr = realloc(*arr, (*arr_size - 1) * sizeof(int));
    if (new_arr == NULL && *arr_size - 1 > 0) {
        perror("Memory reallocation failed");
        exit(EXIT_FAILURE);
    }
    *arr = new_arr;
    (*arr_size)--;
}

void insertBefore(int **arr, int *arr_size, int index, int item) {
    if (index < 0 || index > *arr_size) {
        fprintf(stderr, "Error: Index out of bounds\n");
        return;
    }

    int *new_arr = realloc(*arr, (*arr_size + 1) * sizeof(int));
    if (new_arr == NULL) {
        perror("Memory reallocation failed");
        exit(EXIT_FAILURE);
    }
    *arr = new_arr;

    for (int i = *arr_size; i > index; i--) {
        (*arr)[i] = (*arr)[i - 1];
    }

    (*arr)[index] = item;
    (*arr_size)++;
}
