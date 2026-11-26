#include <stdio.h>
#include <string.h>

int main(void) {
    char str[1000];
    size_t len, i = 0, zeros = 0, ones = 0;
    int valid = 1;

    printf("Enter a binary string (press Enter for epsilon): ");
    if (fgets(str, sizeof(str), stdin) == NULL) return 1;
    str[strcspn(str, "\r\n")] = '\0';
    len = strlen(str);

    /* S -> 0S1 | epsilon generates 0^n 1^n. */
    while (i < len && str[i] == '0') {
        zeros++;
        i++;
    }

    while (i < len && str[i] == '1') {
        ones++;
        i++;
    }

    if (i != len || zeros != ones)
        valid = 0;

    /* Also reject any character other than 0 or 1. */
    for (i = 0; i < len; i++) {
        if (str[i] != '0' && str[i] != '1') valid = 0;
    }

    if (valid)
        printf("Accepted: The string belongs to the language.\\n");
    else
        printf("Rejected: The string does not belong to the language.\\n");

    return 0;
}
