#include <cstdio>

bool check(int x) {
    while (x) {
        int w = x % 16;
        if (x < 10) return 0;
        x /= 16;
    }
    return 1;
}
int main() {
    int i;
    for (i = 2022; !check(i); i++) {
    }
    printf("%d\n", i);
    printf("%d\n", check(2560));
    return 0;
}
