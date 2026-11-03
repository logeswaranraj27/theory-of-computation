#include <stdio.h>
#include <string.h>

int check_nfa(char *str, int index, int state) {
    if (str[index] == '\0') {
        return (state == 2); // State 2 is accepting
    }

    char ch = str[index];
    int matched = 0;

    if (state == 0) {
        if (ch == '0') {
            matched = check_nfa(str, index + 1, 1);
        }
    } else if (state == 1) {
        if (ch == '0' || ch == '1') {
            // NFA choices
            matched = check_nfa(str, index + 1, 1) || check_nfa(str, index + 1, 2);
        }
    } else if (state == 2) {
        if (ch == '0') {
            matched = check_nfa(str, index + 1, 1);
        } else if (ch == '1') {
            matched = check_nfa(str, index + 1, 2);
        }
    }
    return matched;
}

int main() {
    char str[100];
    printf("Enter string (over {0, 1}): ");
    scanf("%s", str);

    if (check_nfa(str, 0, 0))
        printf("Result: ACCEPTED by NFA\n");
    else
        printf("Result: NOT ACCEPTED\n");

    return 0;
}