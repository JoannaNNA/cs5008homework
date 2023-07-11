#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int priority;
    struct Node* next;
} Node;

Node* newNode(int d, int p) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = d;
    temp->priority = p;
    temp->next = NULL;
    return temp;
}

int isEmpty(Node** head) {
    return (*head) == NULL;
}

void enqueue(Node** head, int d, int p) {
    Node* temp = newNode(d, p);
    if (*head == NULL || (*head)->priority > p) {
        temp->next = *head;
        (*head) = temp;
    } else {
        Node* start = (*head);
        while (start->next != NULL && start->next->priority < p) {
            start = start->next;
        }
        temp->next = start->next;
        start->next = temp;
    }
}

void dequeue(Node** head) {
    if (isEmpty(head)) {
        return;
    }
    Node* temp = *head;
    (*head) = (*head)->next;
    free(temp);
}

void display(Node** head) {
    Node* start = (*head);
    while (start != NULL) {
        printf("%d ", start->data);
        start = start->next;
    }
}

int main() {
    Node* pq = NULL;
    int choice, data, priority;

    do {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data and priority: ");
                scanf("%d %d", &data, &priority);
                enqueue(&pq, data, priority);
                break;
            case 2:
                dequeue(&pq);
                break;
            case 3:
                display(&pq);
                break;
            case 4:
                exit(0);
        }
    } while(1);

    return 0;
}
