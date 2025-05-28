#include <stdio.h>

int linear_search(int *arr, size_t size, int num) {
    for (int i=0; i < size; i++)
        if (num == arr[i]) return i;
    return -1;
}

int main() {
    int arr[] = {1, 4, 6, 9, 10, 12};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    printf("\n%d", linear_search(arr, size, 2));

    return 0;
}