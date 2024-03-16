#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int cq[SIZE];
int front = -1;
int rear = -1;

void cqinsert(int val) {
    if (front == -1) {
        front = 0;
    }
    rear = (rear + 1) % SIZE;
    cq[rear] = val;
}

void cqdelete() {
    int item;
    item = cq[front];
    printf("The deleted element is: %d\n", item);
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

void cqdisplay() {
    int i;
    if (front == -1) {
        printf("CQ is Empty\n");
    } else {
        printf("The elements in CQ are:\n");
        for (i = front; i != rear; i = (i + 1) % SIZE) {
            printf("%d\t", cq[i]);
        }
        printf("%d\t", cq[i]); // Print the last element
    }
    printf("\n");
}

int cqfull() {
    if ((rear + 1) % SIZE == front) {
        return 1;
    }
    return 0;
}

int cqempty() {
    if (front == -1) {
        return 1;
    }
    return 0;
}

int main() {
    while (1) {
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        int elem, ch;
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                if (cqfull()) {
                    printf("CQ overflow\n");
                } else {
                    printf("Enter the element to be inserted: ");
                    scanf("%d", &elem);
                    cqinsert(elem);
                }
                break;
            case 2:
                if (cqempty()) {
                    printf("CQ underflow\n");
                } else {
                    cqdelete();
                }
                break;
            case 3:
                cqdisplay();
                break;
            case 4:
                exit(0);
            default:
                printf("Enter valid choice\n");
        }
    }
    return 0;
}               