#include<stdio.h>  
#define max 25

void main() {
    int frag[max], b[max], f[max], i, j, nb, nf;
    static int ff[max];

    printf("\n\tMemory Management Scheme - First Fit"); 
    printf("\nEnter the number of blocks:"); 
    scanf("%d", &nb);
    printf("Enter the number of files:"); 
    scanf("%d", &nf);

    printf("\nEnter the size of the blocks:\n"); 
    for(i = 1; i <= nb; i++) {
        printf("Block %d:", i);
        scanf("%d", &b[i]);
    }

    printf("Enter the size of the files:\n"); 
    for(i = 1; i <= nf; i++) {
        printf("File %d:", i);
        scanf("%d", &f[i]);
    }

    for(i = 1; i <= nf; i++) {
        for(j = 1; j <= nb; j++) {
            if(b[j] >= f[i] && ff[j] != 1) {
                ff[i] = j;
                frag[i] = b[j] - f[i];
                break;
            }
        }
    }

    printf("\nFile_no:\tFile_size:\tBlock_no:\tBlock_size:\tFragment"); 
    for(i = 1; i <= nf; i++)
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, f[i], ff[i], b[ff[i]], frag[i]);
    
    printf("\n");

    // Resetting arrays for the second loop
    for(i = 1; i <= nf; i++) {
        ff[i] = 0;
        frag[i] = 0;
    }

    for(i = 1; i <= nf; i++) {
        for(j = 1; j <= nb; j++) {
            if(b[j] >= f[i] && ff[j] != 1) {
                ff[i] = j;
                frag[i] = b[j] - f[i];
                break;
            }
        }
    }

    printf("\nFile_no:\tFile_size:\tBlock_no:\tBlock_size:\tFragment"); 
    for(i = 1; i <= nf; i++)
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, f[i], ff[i], b[ff[i]], frag[i]);
}

