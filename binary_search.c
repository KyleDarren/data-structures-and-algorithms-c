#include <stdio.h>

int binarySearch(int*, int, int);

int main() {
    int arr[] = {4, 7, 8, 10, 13, 16, 21, 22};
    int arr_size = sizeof(arr) / sizeof(*arr);
    int num = 2;

    printf(" %d ", binarySearch(arr, arr_size, num));
    return 0;
}

int binarySearch(int *arr, int arr_size, int num) {
    int searching = 1;
    int point1 = 0; // First Element
    int point2;
    int point3 = arr_size-1; // Last Element

    while (point1 <= point3) {
        point2 = (point1 + point3) / 2; // Set the middle point into the average of point1 and point2
        if (num == arr[point2]) {
            return point2;
        } else if (num < arr[point2]) {
            point3 = point2 - 1; // Bring to the right of point2
        } else if (num > arr[point2]) {
            point1 = point2 + 1; // Bring to the left of point2
        }
    }

    return -1;
}