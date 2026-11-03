#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    printf("Enter string (over {0, 1}): ");
    scanf("%s", str);

    int state = 0; // State 0: Start
    int i = 0;

    while (str[i] != '\0') {
        char ch = str[i];
        switch (state) {
            case 0:
                if (ch == '0') state = 1;
                else state = 3; // Dead state
                break;
            case 1:
                if (ch == '0') state = 1;
                else state = 2; // Ends with 1 found
                break;
            case 2:
                if (ch == '0') state = 1;
                else state = 2;
                break;
            case 3:
                break; // Dead state
        }
        i++;
    }

    if (state == 2)
        printf("Result: ACCEPTED (Starts with 0 and ends with 1)\n");
    else
        printf("Result: NOT ACCEPTED\n");

    return 0;
}