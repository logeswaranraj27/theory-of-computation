#include <stdio.h>

#define MAX 20

int n; // Number of states
int adj[MAX][MAX]; // Adjacency matrix for epsilon transitions
int closure[MAX];

void find_closure(int state) {
    closure[state] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[state][i] == 1 && closure[i] == 0) {
            find_closure(i);
        }
    }
}

int main() {
    printf("Enter the number of states: ");
    scanf("%d", &n);

    printf("Enter the epsilon transition matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        // Reset closure array for each state
        for (int j = 0; j < n; j++) {
            closure[j] = 0;
        }

        find_closure(i);

        printf("Epsilon-closure of state q%d = { ", i);
        for (int j = 0; j < n; j++) {
            if (closure[j] == 1) {
                printf("q%d ", j);
            }
        }
        printf("}\n");
    }

    return 0;
}