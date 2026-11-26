#include <stdio.h>
#include <string.h>
int main() {
    char a[100], b[100];
    int i, n;
    printf("Enter minuend and subtrahend: ");
    scanf("%s%s", a, b);
    n = strlen(a) - strlen(b);
    if (n < 0) printf("Negative result\n");
    else {
        printf("Difference: ");
        for (i = 0; i < n; i++) printf("a");
        printf("\n");
    }
    return 0;
}
