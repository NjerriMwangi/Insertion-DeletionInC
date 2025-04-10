#include <stdio.h>
#define MAX 10 // Maximum size of the array

// Function prototypes
void insert(int arr[], int* size, int value, int pos);
void delete(int arr[], int* size, int pos);
void display(int arr[], int size);

int main() {
    int arr[MAX];
    int size = 2; // Current number of elements
    int choice, value, pos;

    while (1) //loop forever unless break is used
	{
        printf("\n=== Array Operations ===\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position (0 to %d): ", size);
                scanf("%d", &pos);
                insert(arr, &size, value, pos);
                break;
            case 2:
                printf("Enter position to delete (0 to %d): ", size - 1);
                scanf("%d", &pos);
                delete(arr, &size, pos);
                break;
            case 3:
                display(arr, size);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

// Insert element at given position
void insert(int arr[], int* size, int value, int pos) {
    if (*size >= MAX) {
        printf("Array is full! Cannot insert.\n");
        return;
    }
    if (pos < 0 || pos > *size) {
        printf("Invalid position! Position should be between 0 and %d.\n", *size);
        return;
    }

    // Shift elements to the right
    int i;
    for(i = *size; i > pos; i--) 
	{
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    (*size)++;
    printf("Inserted %d at position %d successfully\n", value, pos);
}

// Delete element at given position
void delete(int arr[], int* size, int pos) {
    if (*size == 0) {
        printf("Array is empty! Cannot delete.\n");
        return;
    }
    /*if (pos < 0 || pos >= *size) {
        printf("Invalid position! Position should be between 0 and %d.\n", *size - 1);
        return;
    }

    int deletedValue = arr[pos];
    Shift elements to the left */
    
    int i;
    for (i = pos; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
   // printf("Deleted %d from position %d successfully\n", deletedValue, pos);
}

// Display array elements
void display(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty!\n");
        return;
    }
    printf("Array elements: ");
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
