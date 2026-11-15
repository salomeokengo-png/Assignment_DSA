#include <stdio.h>

int main() {
    int n;
    long long a = 0, b = 1, next;

    printf("Enter the term position: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive position.\n");
        return 0;
    }

    for (int i = 1; i < n; i++) {
        next = a + b;
        a = b;
        b = next;
    }

    printf("Term %d = %lld\n", n, a);

    return 0;
}
