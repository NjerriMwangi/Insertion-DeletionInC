#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
void insert(struct Node** head, int value);
void delete(struct Node** head, int value);
void search(struct Node* head, int value);
void traverse(struct Node* head);
void menu();

// Main function
int main() {
    struct Node* head = NULL;
    menu(&head);
    return 0;
}

// Insert a new node at the end
void insert(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        printf("Node inserted successfully\n");
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Node inserted successfully\n");
}

// Delete a node with given value
void delete(struct Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If head node contains the value
    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        printf("Node deleted successfully\n");
        return;
    }

    // Search for the value to be deleted
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node deleted successfully\n");
}

// Search for a value
void search(struct Node* head, int value) {
    struct Node* temp = head;
    int position = 1;
    
    while (temp != NULL) {
        if (temp->data == value) {
            printf("Value %d found at position %d\n", value, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Value %d not found in the list\n", value);
}

// Traverse and display the list
void traverse(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    printf("List elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Menu function
void menu(struct Node** head) {
    int choice, value;
    
    while (1) {
        printf("\n=== Linked List Operations ===\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(head, value);
                break;
                
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                delete(head, value);
                break;
                
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(*head, value);
                break;
                
            case 4:
                traverse(*head);
                break;
                
            case 5:
                printf("Exiting...\n");
                // Free memory before exit
                while (*head != NULL) {
                    struct Node* temp = *head;
                    *head = (*head)->next;
                    free(temp);
                }
                return;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
