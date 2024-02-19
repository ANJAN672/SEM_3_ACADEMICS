#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct {
    char dname[10], fname[10][10];
    int fcnt;
} dir;

void main() {
    int i, ch;
    char f[30];
    dir.fcnt = 0;

    printf("\nEnter name of directory -- ");
    scanf("%s", dir.dname);

    while(1) {
        printf("\n\n1. Create File\t2. Delete File\t3. Search File \n4. Display Files\t5. Exit\nEnter your choice -- ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("\nEnter the name of the file -- ");
                scanf("%s", dir.fname[dir.fcnt]);
                dir.fcnt++;
                break;

            case 4:
                printf("\nDisplay Files\n");
                for (i = 0; i < dir.fcnt; i++)
                    printf("%s ", dir.fname[i]);
                break;

            case 3:
                printf("\nEnter the name of the file -- ");
                scanf("%s", f);

                for (i = 0; i < dir.fcnt; i++) {
                    if (strcmp(f, dir.fname[i]) == 0) {
                        printf("File %s found", f);
                        goto jmp;
                    }
                }

                printf("File %s not found", f);
                jmp: break;

            case 5:
                exit(0);
        }
    }
}
