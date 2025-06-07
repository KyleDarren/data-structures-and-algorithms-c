#include <stdio.h>

int linearSearch(int *arr, size_t size, int num) {
    for (int i=0; i < size; i++)
        if (num == arr[i]) return i;
    return -1;
}

int binarySearch(int *arr, size_t size, int num) {
    int mid, left, right;
    left = 0;
    right = size-1;
    while (left <= right) {
        mid = (left + right)/2;

        if (num == arr[mid]) {
            return mid;
        } else if (num > arr[mid]) {
            left = mid+1;
        } else {
            right = mid-1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 4, 6, 9, 10, 12};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    printf("\n%d", binarySearch(arr, size, 12));

    return 0;
}