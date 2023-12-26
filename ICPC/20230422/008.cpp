#include <cstdio>

int a[1005], b[1005], n, ans, max;
int main() {
    scanf("%d", &n);
    scanf("%d", &a[1]);
    a[0] = 1;
    for (int i = 2, c; i <= n; i++) {
        scanf("%d", &c);
        if (c < a[a[0]]) {
            a[++a[0]] = c;
        } else {
            if (!b[0] || b[b[0]] < c) {
                b[++b[0]] = c;
            } else {
                ans++;
                if (max < a[0]) max = a[0];
                a[0] = 0;
                while (b[b[0]] > c) a[++a[0]] = b[b[0]--];
                a[++a[0]] = c;
            }
        }
    }
    if (a[0]) {
        if (a[0] > max) max = a[0];
        ans++;
    }
    if (b[0]) {
        if (b[0] > max) max = b[0];
        ans++;
    }
    printf("%d %d", ans, max);
    return 0;
}