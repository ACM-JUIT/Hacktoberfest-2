#include <stdio.h>

int main() {

    int i, n, j = 0, m = 1, nextterm;
    
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    
    printf("Fibonacci Series: ");

    for (i = 1; i <= n; ++i) {
        printf("%d, ", j);
        nextterm = j + m;
        j = m;
        m = nextterm;
    }

    return 0;
}
