#include <stdio.h>
#include <stdlib.h>

// For debugging purposes
void print_arr(int *arr, int arr_size) {
    for (int i=0; i < arr_size; i++) {
        printf(" %d ", arr[i]);
    }
}

void merge (int arr[], int f1, int l1, int f2, int l2) {
    int *temp_arr = (int*) malloc(sizeof(int)*(l2+1));
    int i, j, k;
    i = 0;
    j = f1;
    k = f2;

    while (j <= l1 && k <= l2) {
        if (arr[j] <= arr[k]) {
            temp_arr[i++] = arr[j++];
        } else {
            temp_arr[i++] = arr[k++];
        }
    }

    for (;j <= l1; j++) {
        temp_arr[i++] = arr[j];
    }

    for (;k <= l2; k++) {
        temp_arr[i++] = arr[k];
    }

    for (int t=0; t <= l2-f1; t++) {
        arr[t+f1] = temp_arr[t];
    }
}

void mergeSort(int arr[], int first, int last) {
    if (first < last) {
        int mid = (first + last) / 2;
    
        mergeSort(arr, first, mid);
        mergeSort(arr, mid+1, last);
        merge(arr, first, mid, mid+1, last);
    }
}

int main() {
    int arr[] = {3, 2, 6, 4, 1, 8, 7};
    int n = sizeof(arr) / sizeof(arr[1]);

    mergeSort(arr, 0, n-1);

    for (int i=0; i < 7; i++) {
        printf("%d->", arr[i]);
    }
    return 0;
}
