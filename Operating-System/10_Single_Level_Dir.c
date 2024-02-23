#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_NAME_LENGTH 50

struct Directory {
    char files[MAX_FILES][MAX_NAME_LENGTH];
    int file_count;
};

void createFile(struct Directory *dir);
void listFiles(struct Directory *dir);
void deleteFile(struct Directory *dir);

int main() {
    struct Directory single_level_dir;
    single_level_dir.file_count = 0;
    int choice;

    while (1) {
        printf("\nSingle Level Directory Simulation\n");
        printf("1. Create a file\n");
        printf("2. List files\n");
        printf("3. Delete a file\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createFile(&single_level_dir);
                break;
            case 2:
                listFiles(&single_level_dir);
                break;
            case 3:
                deleteFile(&single_level_dir);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter again.\n");
        }
    }

    return 0;
}

void createFile(struct Directory *dir) {
    if (dir->file_count == MAX_FILES) {
        printf("Directory is full. Cannot create more files.\n");
        return;
    }

    printf("Enter file name: ");
    scanf("%s", dir->files[dir->file_count]);
    printf("File '%s' created successfully.\n", dir->files[dir->file_count]);
    dir->file_count++;
}

void listFiles(struct Directory *dir) {
    if (dir->file_count == 0) {
        printf("Directory is empty.\n");
        return;
    }

    printf("Files in the directory:\n");
    for (int i = 0; i < dir->file_count; i++) {
        printf("%d. %s\n", i + 1, dir->files[i]);
    }
}

void deleteFile(struct Directory *dir) {
    if (dir->file_count == 0) {
        printf("Directory is empty. Nothing to delete.\n");
        return;
    }

    char filename[MAX_NAME_LENGTH];
    printf("Enter the name of the file to delete: ");
    scanf("%s", filename);

    int found = 0;
    for (int i = 0; i < dir->file_count; i++) {
        if (strcmp(dir->files[i], filename) == 0) {
            found = 1;
            printf("File '%s' deleted successfully.\n", dir->files[i]);
            strcpy(dir->files[i], dir->files[dir->file_count - 1]);
            dir->file_count--;
            break;
        }
    }

    if (!found)
        printf("File '%s' not found in the directory.\n", filename);
}