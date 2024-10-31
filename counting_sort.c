#include <stdio.h>
#include <stdlib.h>

int max_arr(int *arr, int size);

int main()
{
    // Create a static array
    int arr[] = {1, 2, 0, 0, 3, 2, 1, 2, 3, 4, 1, 6, 9, 4, 3, 8, 1, 2};
    int arr_size = sizeof(arr) / sizeof(*arr);

    // Create a dynamic array
    int *dyn_arr = (int *)malloc(arr_size * sizeof(int));

    // Copy the static array to the dynamic array
    for (int i = 0; i < arr_size; i++)
    {
        dyn_arr[i] = arr[i];
    }

    int max = max_arr(dyn_arr, arr_size);

    // Allocate a specific amount of memory based on the maximum value inside the array
    int *count_list = (int *)malloc((max + 1) * sizeof(int));

    // Set each item of the count_list to 0
    for (int i = 0; i < arr_size; i++)
    {
        count_list[i] = 0;
    }

    // Increment the index
    for (int i = 0; i < arr_size; i++)
    {
        count_list[dyn_arr[i]]++;
    }

    free(dyn_arr);

    int *result_arr = (int *)malloc(arr_size * sizeof(int));
    int base_index = 0;
    for (int i = 0; i < (max + 1); i++)
    {
        for (int j = 0; j < count_list[i]; j++)
        {
            result_arr[base_index] = i;
            base_index++;
        }
    }

    // Output
    printf("\n");
    for (int i = 0; i < max + 1; i++)
    {
        printf("%d ", count_list[i]);
    }

    printf("\n");
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d ", result_arr[i]);
    }

    return 0;
}

// Return the maximum value of the array
int max_arr(int *arr, int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}