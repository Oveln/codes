#include <cstdio>

int T = 64, ans = 1000000000, Ans = -1, x;
int calc(int x) {
    int ret = 0;
    while (x) {
        ret += x % 10;
        x /= 10;
    }
    return ret;
}
int main() {
    while (T--) {
        scanf("%d", &x);
        if (ans > calc(x)) {
            ans = calc(x);
            Ans = x;
        }
    }
    printf("%d %d", ans, Ans);
    return 0;
}
