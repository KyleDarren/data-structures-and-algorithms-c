#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main() {
    int guess_count = 0;
    int magic_number = (rand() % (100 - 0 + 1)) + 0;
    while (guess_count < 5) {
        int input_number;
        scanf("%d", &input_number);
        if (input_number > magic_number) {
            printf("Your guess is high!");
        } else if (input_number < magic_number) {
            printf("Your guess is too low!");
        } else {
            printf("Your guess is correct");
            break;
        }
        guess_count++;
    }
    if ((guess_count < 5) == false) {
        printf("%d", magic_number);
        printf("\nYou run out of chances!");
    }
}
