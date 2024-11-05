#include <stdio.h>
#include <stdlib.h>

int existIn(int num, int *arr, int arr_size);
void insert(int **arr, int item, int *arr_size);

int main() {
    printf("\n");
    int rows = 50;
    int cols = 2*rows-1;
    int mids_size = 1;
    int *mids = (int*)calloc(mids_size, sizeof(int));
    mids[0] = cols / 2 + 1;
    char word[] = "merrychristmas"; // Put here your prefered word
    int word_index = 0;

    for (int r = 1; r <= rows; r++) {
        for (int c = 1; c <= cols; c++) {
            if (existIn(c, mids, mids_size)) {
                printf("%c", word[word_index]);
                word_index++;
                if (word_index > sizeof(word)/sizeof(*word)-2) {
                    word_index = 0;
                }
            } else {
                printf(" ");
            }
        }
        printf("\n");

        // Create a temporary array
        int temp_arr_size = 1;
        int *temp_arr = (int*)calloc(temp_arr_size, sizeof(int));

        // Put to the first element of temp_arr the decremented first element of mids
        temp_arr[0] = mids[0] - 1;

        // Insert the values of mids to temp_arr
        for (int i = 0; i < mids_size; i++) {
            insert(&temp_arr, mids[i], &temp_arr_size);
        }

        // Insert the incremented last element of mids
        insert(&temp_arr, mids[mids_size - 1] + 1, &temp_arr_size);

        // Assign the value of temp_arr_size to mids_size
        mids_size = temp_arr_size;

        // Reallocate the mids
        mids = realloc(mids, mids_size * sizeof(int));

        // Copy the temp_arr to the mids
        for (int i = 0; i < mids_size; i++) {
            mids[i] = temp_arr[i];
        }

        free(temp_arr);  
    }

    free(mids);  
    return 0;
}

int existIn(int num, int *arr, int arr_size) {
    int result = 0;
    for (int i = 0; i < arr_size; i++) {
        if (num == arr[i]) {
            result = 1;
            break;
        }
    }
    return result;
}

void insert(int **arr, int item, int *arr_size) {
    *arr_size += 1;
    *arr = realloc(*arr, *arr_size * sizeof(int));
    (*arr)[*arr_size - 1] = item;
}
