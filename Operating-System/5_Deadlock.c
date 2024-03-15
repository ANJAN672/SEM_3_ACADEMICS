#include <stdio.h>
#include <string.h>

int main() {
    int alloc[10][10], max[10][10];
    int avail[10], work[10], total[10];
    int need[10][10];
    int i, j, k, n, m;
    int count = 0;
    char finish[10];

    printf("Enter the number of processes and resources: ");
    scanf("%d%d", &n, &m);

    for (i = 0; i < n; i++)
        finish[i] = 'n';

    printf("Enter the claim matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter the allocation matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter the resource vector:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &total[i]);
        avail[i] = 0;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            avail[j] += alloc[i][j];
        }
    }

    for (i = 0; i < m; i++)
        work[i] = total[i];

    while (count < n) {
        int allocated = 0;

        for (i = 0; i < n; i++) {
            if (finish[i] == 'n') {
                int safe = 1;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        safe = 0;
                        break;
                    }
                }

                if (safe) {
                    printf("All resources can be allocated to Process %d\n", i + 1);
                    printf("Available resources are: ");
                    
                    for (k = 0; k < m; k++) {
                        work[k] += alloc[i][k];
                        printf("%4d", work[k]);
                    }

                    printf("\nProcess %d executed\n", i + 1);
                    finish[i] = 'y';
                    count++;
                    allocated = 1;
                }
            }
        }

        if (!allocated) {
            printf("System is not in a safe state\n");
            break;
        }
    }

    if (count == n)
        printf("System is in a safe state\n");

    return 0;
}
