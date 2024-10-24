#include <stdio.h>

int main() {
    int arr[] = {5, 6, 2, 4, 1, 20};
    int minVal = arr[0];

    for (int i = 0; i < sizeof arr / sizeof *arr; i++) {
        if (arr[i] < minVal) minVal = arr[i];
    }

    printf("%d", minVal);

    return 0;
}