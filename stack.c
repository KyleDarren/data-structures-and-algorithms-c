#include <stdio.h>
#include <stdlib.h>

struct Element {
    char data;
    struct Element *below;
};

void traverse(struct Element* top) {
    struct Element* temp;

    temp = top;
    while (temp != NULL) {
        printf("%c->", temp->data);
        temp = temp->below;
    }
}

void push(struct Element **top, char data) {
    struct Element *newElement = (struct Element*) malloc(sizeof(struct Element));
    
    if (newElement == NULL) return;

    newElement->data = data;

    newElement->below = *top;
    *top = newElement;
}

void pop(struct Element **top) {
    if (*top == NULL) return;

    struct Element *toDelete = *top;
    *top = toDelete->below;

    free(toDelete);
}

void deleteStack(struct Element **top) {
    struct Element *toDelete;

    while (*top != NULL) {
        toDelete = *top;
        
        *top = toDelete->below;
        free(toDelete);
    }
}

int main() {
    struct Element *top;

    char data[] = {'a', 'b', 'c', 'd', 'e'};

    top = NULL;

    for (int i=0; i < sizeof(data)/sizeof(data[0]); i++) {
        push(&top, data[i]);
    }

    pop(&top);

    traverse(top);

    deleteStack(&top);

    return 0;
}