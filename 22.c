#include <stdio.h>
#include <string.h>

int main(void) {
    char str[1000];
    size_t left, right, len;
    int valid = 1;

    printf("Enter a binary string (press Enter for epsilon): ");
    if (fgets(str, sizeof(str), stdin) == NULL) return 1;
    str[strcspn(str, "\r\n")] = '\0';
    len = strlen(str);

    /* S -> 0S0 | 1S1 | 0 | 1 | epsilon generates binary palindromes. */
    for (left = 0; left < len; left++) {
        if (str[left] != '0' && str[left] != '1') {
            valid = 0;
            break;
        }
    }

    if (valid) {
        left = 0;
        right = len;
        while (left < right) {
            right--;
            if (str[left] != str[right]) {
                valid = 0;
                break;
            }
            left++;
        }
    }

    if (valid)
        printf("Accepted: The string belongs to the language.\\n");
    else
        printf("Rejected: The string does not belong to the language.\\n");

    return 0;
}
