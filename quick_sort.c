#include <stdio.h>
#include <stdlib.h>

void quickSort(int *arr, size_t arr_size, int low, int high);
int partition(int *arr, size_t arr_size);

int main() {
    int arr[] = {8, 7, 6, 5};
    int arr_size = sizeof(arr)/sizeof(*arr);
    quickSort(arr, arr_size, 0, arr_size);
    printf("\n");
    for (int i=0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
return 0;
}

void quickSort(int *arr, size_t arr_size, int low, int high) {
    if (arr_size > 1) {
        // Set the last element as the pivot element
        int pivot = arr[high-1];
        int pivot_index;
        int high_item = -1;
        int high_index = -1;
        for (int i=low; i < high; i++) {
            if (arr[i] <= pivot && high_index != -1) {
                int temp = arr[i];
                arr[i] = arr[high_index];
                arr[high_index] = temp;
                pivot_index = high_index;
                high_index = i;
            } else if (arr[i] > pivot && high_item == -1) {
                high_item = arr[i];
                high_index = i;
            }
            
        }
        
        quickSort(arr, pivot_index+1, low, pivot_index);
        quickSort(arr, high-pivot_index, pivot_index, high);

    }
    
}

// Returns a pivot index and modify the array
int partition(int *arr, size_t arr_size) {

    return 0;
}