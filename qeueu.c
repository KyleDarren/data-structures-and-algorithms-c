#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// struct Element {
//     char data;
//     struct Element *front;
// };

// struct Qeueu {
//     struct Element *front;
//     struct Element *rear;
// };

// void enqeueu(struct Element **rear, char data) {
//     struct Element *newElement = (struct Element*) malloc(sizeof(struct Element));

//     if (newElement == NULL)  return;

//     newElement->data = data;
//     newElement->front = *rear;
//     *rear = newElement;
// }

// void deqeueu(struct Element *rear) {
//     struct Element *toDelete, *prevElement;

//     toDelete = rear;
//     prevElement = rear;

//     while (toDelete->front != NULL)
//         toDelete = toDelete->front;

//     while(prevElement->front != toDelete)
//         prevElement = prevElement->front;
    
//     prevElement->front = NULL;
//     free(toDelete);
// }

// int traverse(struct Element *rear) {
//     struct Element *temp = rear;

//     while (temp != NULL) {
//         printf("%c->", temp->data);
//         temp = temp->front;
//     }
// }

// int main() {
//     char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};

//     struct Element *rear = NULL;

//     for (int i=0; i < sizeof(data)/sizeof(data[0]); i++)
//         enqeueu(&rear, data[i]);

//     enqeueu(&rear, 'g');
//     deqeueu(rear);

//     traverse(rear);

//     return 0;
// }

struct Element {
    int data;
    struct Element *next;
    struct Element *prev;
};

struct Qeueu {
    struct Element *front;
    struct Element *rear;
};

void enqeueu(struct Qeueu *qeueu, int data) {
    struct Element *newElement = (struct Element*) malloc(sizeof(struct Element));
    newElement->data = data;
    newElement->next = NULL;
    newElement->prev = NULL;

    if (qeueu->front == NULL) {
        qeueu->front = newElement;
        qeueu->rear = newElement;
    } else {
        newElement->next = qeueu->rear;
        qeueu->rear->prev = newElement;
        qeueu->rear = newElement;
    }
}

void deqeueu(struct Qeueu *qeueu) {
    if (qeueu->front == NULL) {
        printf("List is empty");
    } else if (qeueu->front == qeueu->rear) {
        free(qeueu->front);
        qeueu->front = NULL;
        qeueu->rear = NULL;
    } else {
        struct Element *toDelete;
        toDelete = qeueu->front;
        qeueu->front = toDelete->prev;
        qeueu->front->next = NULL;
        free(toDelete);
    }
}

void traverse(struct Qeueu qeueu) {
    struct Element *temp;
    temp = qeueu.front;

    while (temp != NULL) {
        printf("<-%d", temp->data);
        temp = temp->prev;
    }
}

int main() {
    int num[5] = {4, 5, 2, 6, 1};
    struct Qeueu qeueu;
    qeueu.front = NULL;
    qeueu.rear = NULL;
    
    for (int i=0; i < 5; i++) {
        enqeueu(&qeueu, num[i]);
    }

    deqeueu(&qeueu);
    deqeueu(&qeueu);
    enqeueu(&qeueu, 3);

    traverse(qeueu);
    return 0;
}