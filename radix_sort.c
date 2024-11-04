#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getDigit(int num, int decimal_place);

int main() {
    int arr[] = {123, 546, 789, 345, 565, 983};
    int arr_size = sizeof(arr) / sizeof(*arr);
    int *dyn_arr = (int*)malloc(arr_size * sizeof(int));

    for (int i=0; i < arr_size; i++) {
        dyn_arr[i] = arr[i];
    }

    // Allocate memory for radix array (2d)
    int rows = 10;
    int cols = 10;
    int **radix = (int**)calloc(rows, sizeof(int*));
    for (int i=0; i < rows; i++) {
        radix[i] = (int*)calloc(cols, sizeof(int));
    }

    int digit_place = 3;

    while (digit_place > 0) {
        for (int i=0; i < arr_size; i++) {
            // Get the digit
            int digit = getDigit(dyn_arr[i], digit_place);
            printf(" %d ", digit);
            // Place the number in the index based on the digit
            // Increment ind until the item 0.
            int ind = 0;
            while (radix[digit][ind] != 0) {
                ind++;
            }
            radix[digit][ind] = dyn_arr[i];
        }

        int ind = 0;
        // Update the partially sorted array
        for (int i=0; i < rows; i++) {
            for (int j=0; j < cols; j++) {
                if(radix[i][j] != 0) {
                    dyn_arr[ind] = radix[i][j];
                    ind++;
                }
            }
        }

        // Reset the radix array
        for (int i=0; i < rows; i++) {
            memset(radix[i], 0, cols * sizeof(int));
        }

        digit_place--;
        

        printf("\n");
        for (int i=0; i < arr_size; i++) {
            printf("%d ", dyn_arr[i]);
        }
    }

    return 0;
}

int getDigit(int num, int decimal_place) {
    char str[4];
    sprintf(str, "%d", num);
    
    return str[decimal_place-1] - '0';
}