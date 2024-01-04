#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int usn;
    char name[20];
    char branch[20];
    int semester;
    char phone[20];
} STUDENT;

struct node {
    int usn;
    char name[20];
    char branch[20];
    int semester;
    char phone[20];
    struct node* link;
};

typedef struct node* NODE;

NODE getnode() {
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    if (x == NULL) {
        printf("Out of memory\n");
        exit(0);
    }
    return x;
}

NODE insert_front(STUDENT item, NODE first) {
    NODE temp;
    temp = getnode();
    temp->usn = item.usn;
    strcpy(temp->name, item.name);
    strcpy(temp->branch, item.branch);
    temp->semester = item.semester;
    strcpy(temp->phone, item.phone);
    temp->link = NULL;
    if (first == NULL)
        return temp;
    temp->link = first;
    return temp;
}

NODE insert_rear(STUDENT item, NODE first) {
    NODE temp, cur;
    temp = getnode();
    temp->usn = item.usn;
    strcpy(temp->name, item.name);
    strcpy(temp->branch, item.branch);
    temp->semester = item.semester;
    strcpy(temp->phone, item.phone);
    temp->link = NULL;
    if (first == NULL)
        return temp;
    cur = first;
    while (cur->link != NULL) {
        cur = cur->link;
    }
    cur->link = temp;
    return first;
}

NODE delete_front(NODE first) {
    NODE temp;
    if (first == NULL) {
        printf("Student list is empty\n");
        return NULL;
    }
    temp = first;
    first = first->link;
    printf("Deleted student record: USN=%d\n", temp->usn);
    free(temp);
    return first;
}

NODE delete_rear(NODE first) {
    NODE cur, prev;
    if (first == NULL) {
        printf("Student list is empty, cannot delete\n");
        return first;
    }
    if (first->link == NULL) {
        printf("Deleted student record: USN=%d\n", first->usn);
        free(first);
        return NULL;
    }
    prev = NULL;
    cur = first;
    while (cur->link != NULL) {
        prev = cur;
        cur = cur->link;
    }
    printf("Deleted student record: USN=%d\n", cur->usn);
    free(cur);
    prev->link = NULL;
    return first;
}

void display(NODE first) {
    NODE cur;
    int count = 0;
    if (first == NULL) {
        printf("Student list is empty\n");
        return;
    }
    cur = first;
    while (cur != NULL) {
        printf("%d\t%s\t%s\t%d\t%s\n", cur->usn, cur->name, cur->branch, cur->semester, cur->phone);
        cur = cur->link;
        count++;
    }
    printf("Number of students = %d\n", count);
}

int main() {
    NODE first = NULL;
    int ch;
    STUDENT item;

    for (;;) {
        printf("1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (ch) {
            case 1:
                printf("USN: ");
                scanf("%d", &item.usn);
                printf("Name: ");
                scanf("%s", item.name);
                printf("Branch: ");
                scanf("%s", item.branch);
                printf("Semester: ");
                scanf("%d", &item.semester);
                printf("Phone: ");
                scanf("%s", item.phone);
                first = insert_front(item, first);
                break;

            case 2:
                printf("USN: ");
                scanf("%d", &item.usn);
                printf("Name: ");
                scanf("%s", item.name);
                printf("Branch: ");
                scanf("%s", item.branch);
                printf("Semester: ");
                scanf("%d", &item.semester);
                printf("Phone: ");
                scanf("%s", item.phone);
                first = insert_rear(item, first);
                break;

            case 3:
                first = delete_front(first);
                break;

            case 4:
                first = delete_rear(first);
                break;

            case 5:
                display(first);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

