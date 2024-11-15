#include <stdio.h>
#include <stdlib.h>

// For debugging purposes
void print_arr(int *arr, int arr_size) {
    for (int i=0; i < arr_size; i++) {
        printf(" %d ", arr[i]);
    }
}

void removeFirst(int **arr, int arr_size) {
    // Copy the array to a temporary array
    int *temp_arr = (int*)calloc(arr_size, sizeof(int));
    for (int i=0; i < arr_size; i++) {
        temp_arr[i] = (*arr)[i];
    }

    // Reallocate the array
    *arr = realloc(*arr, (arr_size-1) * sizeof(int));
    for (int i=0; i < arr_size-1; i++) {
        (*arr)[i] = temp_arr[i+1];
    }
}

void insertBefore(int **arr, int arr_size, int index, int item) {
    *arr = realloc(*arr, (arr_size+1)*sizeof(int));
    for (int i=arr_size; i > index; i--) {
        (*arr)[i] = (*arr)[i-1];
    }
    (*arr)[index] = item;
}

int main() {
    int left_arr[] = {1, 3, 5, 7};
    int *left_arr_dyn = (int*)calloc(4, sizeof(int));
    for (int i=0; i < 4; i++) {
        left_arr_dyn[i] = left_arr[i];
    }
    
    insertBefore(&left_arr_dyn, 4, 1, 5);

    print_arr(left_arr_dyn, 5);


    
    return 0;
}