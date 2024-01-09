#include <stdio.h>
#include <string.h>

int main() {
    char STR[100], PAT[100], REP[100], ans[100];
    int i, m, c, j, flag = 0;

    printf("\nEnter the MAIN string: \n");
    gets(STR);

    printf("\nEnter a PATTERN string: \n");
    gets(PAT);

    printf("\nEnter a REPLACE string: \n");
    gets(REP);

    i = m = c = j = 0;

    while (STR[c] != '\0') {
        // Checking for Match
        if (STR[m] == PAT[i]) {
            i++;
            m++;
            flag = 1;

            if (PAT[i] == '\0') {
                // Copy replace string in ans string
                for (int k = 0; REP[k] != '\0'; k++, j++)
                    ans[j] = REP[k];

                i = 0;
                c = m;
            }
        } else { // Mismatch
            ans[j] = STR[c];
            j++;
            c++;
            m = c;
            i = 0;
        }
    }

    if (flag == 0) {
        printf("Pattern not found!!!\n");
    } else {
        ans[j] = '\0';
        printf("\nThe RESULTANT string is: %s\n", ans);
    }

    return 0;
}

