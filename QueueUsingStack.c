#include <stdio.h>
#define MAX 5 // Maximum size of each stack

// Stack structure
struct Stack {
    int arr[MAX];
    int top;
};

// Queue structure using two stacks
struct Queue {
    struct Stack s1; // For enqueue
    struct Stack s2; // For dequeue
};

// Function prototypes
void push(struct Stack* s, int value);
int pop(struct Stack* s);
int isFull(struct Stack* s);
int isEmpty(struct Stack* s);
void enqueue(struct Queue* q, int value);
void dequeue(struct Queue* q);
void display(struct Queue* q);

int main() {
    struct Queue q;
    q.s1.top = -1;
    q.s2.top = -1;
    int choice, value;

    while (1) {
        printf("\n=== Queue using Two Stacks ===\n");
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

// Stack operations
int isFull(struct Stack* s) {
    return (s->top == MAX - 1);
}

int isEmpty(struct Stack* s) {
    return (s->top == -1);
}

void push(struct Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack is full!\n");
        return;
    }
    s->top++;
    s->arr[s->top] = value;
}

int pop(struct Stack* s) {
    if (isEmpty(s)) {
        return -1; // Indicates empty stack
    }
    int value = s->arr[s->top];
    s->top--;
    return value;
}

// Queue operations
void enqueue(struct Queue* q, int value) {
    if (isFull(&q->s1)) {
        printf("Queue is full!\n");
        return;
    }
    push(&q->s1, value);
    printf("Enqueued %d successfully\n", value);
}

void dequeue(struct Queue* q) {
    if (isEmpty(&q->s1) && isEmpty(&q->s2)) {
        printf("Queue is empty!\n");
        return;
    }

    // If s2 is empty, transfer all elements from s1 to s2
    if (isEmpty(&q->s2)) {
        while (!isEmpty(&q->s1)) {
            int value = pop(&q->s1);
            push(&q->s2, value);
        }
    }

    int value = pop(&q->s2);
    if (value != -1) {
        printf("Dequeued %d\n", value);
    }
}

void display(struct Queue* q) {
    if (isEmpty(&q->s1) && isEmpty(&q->s2)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");
    
    // Display s2 elements (front of queue) in reverse order
    for (int i = q->s2.top; i >= 0; i--) {
        printf("%d ", q->s2.arr[i]);
    }
    
    // Display s1 elements (rear of queue) in order
    for (int i = 0; i <= q->s1.top; i++) {
        printf("%d ", q->s1.arr[i]);
    }
    printf("\n");
}

