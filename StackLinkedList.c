#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

// Function prototypes
void push(struct Stack* s, int value);
void pop(struct Stack* s);
void peek(struct Stack* s);
void display(struct Stack* s);

int main() {
    struct Stack s;
    s.top = NULL;
    int choice, value;

    while (1) {
        printf("\n=== Stack Operations (Linked List) ===\n");
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
                // Free memory
                while (s.top != NULL) {
                    struct Node* temp = s.top;
                    s.top = s.top->next;
                    free(temp);
                }
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}

void push(struct Stack* s, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
    printf("Pushed %d successfully\n", value);
}

void pop(struct Stack* s) {
    if (s->top == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    struct Node* temp = s->top;
    printf("Popped %d\n", temp->data);
    s->top = s->top->next;
    free(temp);
}

void peek(struct Stack* s) {
    if (s->top == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Top element is %d\n", s->top->data);
}

void display(struct Stack* s) {
    if (s->top == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    struct Node* temp = s->top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
