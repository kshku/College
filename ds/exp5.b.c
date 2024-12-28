#include <stdio.h>

void solve(int n, char A, char B, char C) {
    if (n == 0) return;
    solve(n - 1, A, C, B);
    printf("Move disk %d from peg %c to %c\n", n, A, C);
    solve(n - 1, B, A, C);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("The sequence of moves involved in teh tower of Honoi are:\n");
    solve(n, 'A', 'B', 'C');
}
