#include <cstdio>

int x, n;
int main() {
    scanf("%d", &n);
    for (int i = 1, now; i <= 2 * n + 1; i++) scanf("%d", &now), x ^= now;
    printf("%d\n", x);
    return 0;
}