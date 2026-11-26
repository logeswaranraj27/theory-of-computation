#include <stdio.h>
#include <string.h>

int main(void) {
    char str[1000];
    size_t len, i;

    printf("Enter a binary string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) return 1;
    str[strcspn(str, "\r\n")] = '\0';
    len = strlen(str);

    /* S -> 0A1, where A can be any binary string (including empty). */
    int valid = (len >= 2 && str[0] == '0' && str[len - 1] == '1');

    for (i = 0; i < len && valid; i++) {
        if (str[i] != '0' && str[i] != '1') valid = 0;
    }

    if (valid)
        printf("Accepted: The string belongs to the language.\\n");
    else
        printf("Rejected: The string does not belong to the language.\\n");

    return 0;
}
