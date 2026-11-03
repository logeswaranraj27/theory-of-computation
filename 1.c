#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    printf("Enter string (over {a, b}): ");
    scanf("%s", str);

    int state = 0; // State 0: Start state
    int i = 0;

    while (str[i] != '\0') {
        char ch = str[i];
        switch (state) {
            case 0:
                if (ch == 'a') state = 1;
                else state = 3; // Dead state
                break;
            case 1:
                if (ch == 'a') state = 2;
                else state = 1;
                break;
            case 2:
                if (ch == 'a') state = 2;
                else state = 1;
                break;
            case 3:
                break; // Stay in dead state
        }
        i++;
    }

    if (state == 2)
        printf("Result: ACCEPTED (Starts and ends with 'a')\n");
    else
        printf("Result: NOT ACCEPTED\n");

    return 0;
}