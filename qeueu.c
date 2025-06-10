#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Element {
    char data;
    struct Element *front;
};

void enqeueu(struct Element **rear, char data) {
    struct Element *newElement = (struct Element*) malloc(sizeof(struct Element));

    if (newElement == NULL)  return;

    newElement->data = data;
    newElement->front = *rear;
    *rear = newElement;
}

void deqeueu(struct Element *rear) {
    struct Element *toDelete, *prevElement;

    toDelete = rear;
    prevElement = rear;

    while (toDelete->front != NULL)
        toDelete = toDelete->front;

    while(prevElement->front != toDelete)
        prevElement = prevElement->front;
    
    prevElement->front = NULL;
    free(toDelete);
}

int traverse(struct Element *rear) {
    struct Element *temp = rear;

    while (temp != NULL) {
        printf("%c->", temp->data);
        temp = temp->front;
    }
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};

    struct Element *rear = NULL;

    for (int i=0; i < sizeof(data)/sizeof(data[0]); i++)
        enqeueu(&rear, data[i]);

    enqeueu(&rear, 'g');
    deqeueu(rear);

    traverse(rear);

    return 0;
}