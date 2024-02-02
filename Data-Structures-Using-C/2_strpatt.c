#include <stdio.h>
#include <string.h>

int main() {
    char STR[100], PAT[100], REP[100], ans[100]; // Declare four character arrays for the main string, pattern, replacement, and the resultant string
    int i, m, c, j, flag = 0; // Declare integer variables for loop counters and a flag to track pattern presence

    printf("\nEnter the MAIN string: \n");
    gets(STR); // Read the main string from the user

    printf("\nEnter a PATTERN string: \n");
    gets(PAT); // Read the pattern to be replaced from the user

    printf("\nEnter a REPLACE string: \n");
    gets(REP); // Read the replacement string from the user

    i = m = c = j = 0; // Initialize loop counters and indices

    while (STR[c] != '\0') { // Loop through the main string until the end is reached
        // Checking for Match
        if (STR[m] == PAT[i]) { // Check if the current characters match in the main string and pattern
            i++; // Move to the next character in the pattern
            m++; // Move to the next character in the main string
            flag = 1; // Set the flag to indicate a match

            if (PAT[i] == '\0') { // Check if the entire pattern has been matched
                // Copy replace string in ans string
                for (int k = 0; REP[k] != '\0'; k++, j++)
                    ans[j] = REP[k]; // Copy the replacement string to the resultant string
                i = 0; // Reset the pattern index
                c = m; // Move the main string index to the next position after the matched pattern
            }
        } else { // Mismatch
            ans[j] = STR[c]; // Copy the character from the main string to the resultant string
            j++; // Move to the next position in the resultant string
            c++; // Move to the next character in the main string
            m = c; // Reset the pattern matching index
            i = 0; // Reset the pattern index
        }
    }

    if (flag == 0) {
        printf("Pattern not found!!!\n"); // If no match is found, print a message
    } else {
        ans[j] = '\0'; // Add null terminator to the resultant string
        printf("\nThe RESULTANT string is: %s\n", ans); // Print the resultant string
    }

    return 0;
}
