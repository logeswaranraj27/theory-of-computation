#include <stdio.h>
#include <string.h>

int main(void) {
    char str[1000];
    size_t len, i, leading_zeros = 0, trailing_zeros = 0;
    size_t middle_ones = 0;
    int valid = 1;

    printf("Enter a binary string (press Enter for epsilon): ");
    if (fgets(str, sizeof(str), stdin) == NULL) return 1;
    str[strcspn(str, "\r\n")] = '\0';
    len = strlen(str);

    /* S -> 0S0 | A, A -> 1A | epsilon
       Language: 0^n 1^m 0^n, for n,m >= 0. */

    for (i = 0; i < len; i++) {
        if (str[i] != '0' && str[i] != '1') {
            valid = 0;
            break;
        }
    }

    if (valid) {
        while (leading_zeros < len && str[leading_zeros] == '0')
            leading_zeros++;

        i = leading_zeros;
        while (i < len && str[i] == '1') {
            middle_ones++;
            i++;
        }

        trailing_zeros = len - i;
        while (i < len && str[i] == '0') i++;

        if (i != len || leading_zeros != trailing_zeros)
            valid = 0;
    }

    if (valid)
        printf("Accepted: The string belongs to the language.\\n");
    else
        printf("Rejected: The string does not belong to the language.\\n");

    return 0;
}
