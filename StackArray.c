#include <stdio.h>
#define MAX 5 // Maximum size of stack

struct Stack {
    int arr[MAX];
    int top;
};

// Function prototypes
void push(struct Stack* s, int value);
void pop(struct Stack* s);
void peek(struct Stack* s);
void display(struct Stack* s);
int isFull(struct Stack* s);
int isEmpty(struct Stack* s);

int main() {
    struct Stack s;
    s.top = -1;
    int choice, value;

    while (1) {
        printf("\n=== Stack Operations (Array) ===\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                peek(&s);
                break;
            case 4:
                display(&s);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}

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
    printf("Pushed %d successfully\n", value);
}

void pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Popped %d\n", s->arr[s->top]);
    s->top--;
}

void peek(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Top element is %d\n", s->arr[s->top]);
}

void display(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}
