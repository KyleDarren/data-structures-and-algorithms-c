#include <stdio.h>
#include <stdlib.h>

void traverse(int* arr, int size) {
    for (int i=0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

void unsortedInsert(int *arr, int *size, int element) {
    arr[*size] = element;
    (*size)++;
}

void sortedInsert(int *arr, int *size, int element) {
    int temp, i;
    for (i=*size-1; element < arr[i] && i >= 0; i--) {
        arr[i+1] = arr[i];
    }
    arr[i+1] = element;
    (*size)++;
}

void unsortedDelete(int *arr, int *size, int index_to_delete) {
    int temp = arr[index_to_delete];
    arr[index_to_delete] = arr[*size-1];
    (*size)--;
}

void sortedDelete(int *arr, int *size, int index_to_delete) {
    for (int i=index_to_delete; i < *size-1; i++) {
        arr[i] = arr[i+1];
    }
    (*size)--;
}

// Linear Search
int unsortedSearch(int *arr, int size, int target) {
    for (int i=0; i < size; i++) {
        if (target == arr[i]) {
            return 0;
        }
    }
    return -1;
}

// Binary Search
int sortedSearch(int *arr, int size, int target) {
    int mid, first, last;
    first = 0;
    last = size-1;

    while (first <= last) {
        mid = (last+first) / 2;
        if (arr[mid] == target) {
            return 0;
        } else if (target < arr[mid]) {
            last = mid-1;
        } else if (target > arr[mid]) {
            first = mid + 1;
        }
    }
    return -1;
}

int main() {
    int alloc_size = 7;

    int* unsorted_arr = (int*) malloc(sizeof(int)*alloc_size);
    int unsorted_arr_size = 4;
    unsorted_arr[0] = 7;
    unsorted_arr[1] = 5;
    unsorted_arr[2] = 1;
    unsorted_arr[3] = 9;

    // unsortedInsert(unsorted_arr, &unsorted_arr_size, 3);
    // unsortedDelete(unsorted_arr, &unsorted_arr_size, 1);
    // printf("%d", unsortedSearch(unsorted_arr, unsorted_arr_size, 8));
    // traverse(unsorted_arr, unsorted_arr_size);

    int* sorted_arr = (int*) malloc(sizeof(int)*alloc_size);
    int sorted_arr_size = 4;
    sorted_arr[0] = 1;
    sorted_arr[1] = 2;
    sorted_arr[2] = 3;
    sorted_arr[3] = 4;

    // sortedInsert(sorted_arr, &sorted_arr_size, 0);
    // sortedDelete(sorted_arr, &sorted_arr_size, 3);
    // printf("%d", sortedSearch(sorted_arr, sorted_arr_size, 9));
    // traverse(sorted_arr, sorted_arr_size);

    return 0;
}