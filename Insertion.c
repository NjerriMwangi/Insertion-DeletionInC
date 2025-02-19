#include <stdio.h>

int main() 
{
    int array[100], position, i, n, value;

    printf("Enter number of elements in array\n");
    scanf("%d", &n);

    printf("Enter %d elements\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    printf("Enter the location where you wish to insert an element\n");
    scanf("%d", &position);

    printf("Enter the value to insert\n");
    scanf("%d", &value);

    // Shift elements to the right from the specified position
    for (i = n - 1; i >= position - 1; i--) {
        array[i + 1] = array[i];
    }

    // Insert the new value at the specified position
    array[position - 1] = value;

    // Increment the number of elements in the array
    n++;

    // Print the updated array
    printf("Resultant array is\n");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}