#include <stdio.h>
#include <string.h>

// Simple NFA simulation tracking multiple possible active states using recursion/backtracking
int check_nfa(char *str, int index, int state) {
    if (str[index] == '\0') {
        return (state == 2); // State 2 is accepting
    }

    char ch = str[index];
    int matched = 0;

    if (state == 0) {
        if (ch == 'b') {
            matched = check_nfa(str, index + 1, 1); // Transition to state 1
        }
    } else if (state == 1) {
        if (ch == 'a') {
            // NFA choice: can either loop in state 1 or move to final state 2
            matched = check_nfa(str, index + 1, 1) || check_nfa(str, index + 1, 2);
        } else if (ch == 'b') {
            matched = check_nfa(str, index + 1, 1);
        }
    } else if (state == 2) {
        if (ch == 'a') {
            matched = check_nfa(str, index + 1, 2);
        } else if (ch == 'b') {
            matched = check_nfa(str, index + 1, 1);
        }
    }
    return matched;
}

int main() {
    char str[100];
    printf("Enter string (over {a, b}): ");
    scanf("%s", str);

    if (check_nfa(str, 0, 0))
        printf("Result: ACCEPTED by NFA\n");
    else
        printf("Result: NOT ACCEPTED\n");

    return 0;
}