#include <stdio.h>
#include <string.h>
int main() {
    char a[100], b[100];
    int i, n;
    printf("Enter two unary numbers: ");
    scanf("%s%s", a, b);
    n = strlen(a) + strlen(b);
    printf("Sum: ");
    for (i = 0; i < n; i++) printf("a");
    printf("\n");
    return 0;
}
