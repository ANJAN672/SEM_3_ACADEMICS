#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define max_size 5

int stack[max_size], top = -1, flag = 1;
int i, temp, item, rev[max_size], num[max_size];

void push();
void pop();
void display();
void pali();

int main() {
    int choice;

    printf("\n\n--------STACK OPERATIONS ------ \n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Palindrome\n");
    printf("4. Display\n");
    printf("5. Exit\n ");

    while (1) {
        printf("\nEnter your choice:\t");

        // Check if the input is a valid integer
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a valid integer.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                if (flag)
                    printf("\nThe popped element: %d\t", item);
                temp = top;
                break;
            case 3:
                pali();
                top = temp;
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("\nInvalid choice:\n");
                break;
        }
    }

    return 0;
}
