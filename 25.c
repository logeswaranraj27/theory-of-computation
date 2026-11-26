#include <stdio.h>
#include <string.h>

int main(void) {
    char str[1000];
    size_t len, i;
    int valid = 1, found = 0;

    printf("Enter a binary string (press Enter for epsilon): ");
    if (fgets(str, sizeof(str), stdin) == NULL) return 1;
    str[strcspn(str, "\r\n")] = '\0';
    len = strlen(str);

    /* S -> A101A, A -> 0A | 1A | epsilon.
       Each occurrence of A can independently generate any binary string.
       Therefore, the language is all binary strings containing "101". */

    for (i = 0; i < len; i++) {
        if (str[i] != '0' && str[i] != '1') {
            valid = 0;
            break;
        }
    }

    if (valid) {
        for (i = 0; i + 2 < len; i++) {
            if (str[i] == '1' && str[i + 1] == '0' && str[i + 2] == '1') {
                found = 1;
                break;
            }
        }
    }

    if (valid && found)
        printf("Accepted: The string belongs to the language.\\n");
    else
        printf("Rejected: The string does not belong to the language.\\n");

    return 0;
}
