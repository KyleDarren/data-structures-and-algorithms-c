#include <stdio.h>

void quickSort(int *arr, int low, int high);
int partition(int *arr, int low, int high);

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int arr_size = sizeof(arr)/sizeof(*arr);

    quickSort(arr, 0, arr_size-1);
    
    return 0;
}

void quickSort(int *arr, int low, int high) {
    // If the the sub-array size is 1, the code below will not be executed
    // and the recursion loop will stop there.
    if (low < high) {
        int pivot_index = partition(arr, low, high);
        quickSort(arr, low, pivot_index-1);
        quickSort(arr, pivot_index+1, high);
    }
}

// Returns a pivot index and modify the array
int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j=low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;

            // Switch element.
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swith the pivot element and the (i+1)th element
    int temp1 = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp1;

    printf("\n");
    for (int j=0; j < high+1; j++) {
        printf("%d ", arr[j]);
    }
    
    // Return the position of pivot element.
    return i+1;
}