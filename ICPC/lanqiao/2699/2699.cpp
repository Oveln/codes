#include <cstdio>
#include <map>

const int maxn = 200005;
int n, Q, q, maxai;
int a[maxn];
bool ans[maxn], vis[maxn];
int max(int x, int y) {
    if (x > y) return x;
    return y;
}
int main() {
    scanf("%d%d", &n, &Q);
    if (n == 1) ans[1] = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (vis[a[i]]) ans[1] = 1;
        vis[a[i]] = 1;
        maxai     = max(maxai, a[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 2; j * a[i] <= maxai; j++) ans[j] |= vis[j * a[i]];
    }
    while (Q--) {
        scanf("%d", &q);
        printf("%s\n", ans[q] ? "YES" : "NO");
    }
    return 0;
}