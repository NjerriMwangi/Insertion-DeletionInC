#include <stdio.h>
#define MAX 5 // Maximum size of queue

struct Queue {
    int arr[MAX];
    int front, rear;
};

// Function prototypes
void enqueue(struct Queue* q, int value);
void dequeue(struct Queue* q);
void display(struct Queue* q);
int isFull(struct Queue* q);
int isEmpty(struct Queue* q);

int main() {
    struct Queue q;
    q.front = -1;
    q.rear = -1;
    int choice, value;

    while (1) {
        printf("\n=== Queue Operations (Array) ===\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}

int isFull(struct Queue* q) {
    return (q->rear == MAX - 1);
}

int isEmpty(struct Queue* q) {
    return (q->front == -1 || q->front > q->rear);
}

void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->arr[q->rear] = value;
    printf("Enqueued %d successfully\n", value);
}

void dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Dequeued %d\n", q->arr[q->front]);
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
}

void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}
