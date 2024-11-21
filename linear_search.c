#include <stdio.h>

int linearSearch(int*, int, int);

int main() {
    int arr[] = {5, 7, 9, 4, 8};
    int arr_size = sizeof(arr) / sizeof(*arr);
    int num = 10;
    printf(" %d ", linearSearch(arr, arr_size, num));

    return 0;
}

int linearSearch(int* arr, int arr_size, int num) {
    for (int i=0; i < arr_size; i++) {
        if (num == arr[i]) {
            return i;
        }
    }
    return -1;
}