#include <cstdio>
#define maxn 1005
#define maxC 1005

int n, c, w[maxn], v[maxn], f[maxC];
int ans;
int max(int x, int y) { return x > y ? x : y; }
int main() {
    scanf("%d%d", &n, &c);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &w[i], &v[i]);
    }
    for (int i = 1; i <= c; i++) f[i] = -100000000;
    for (int i = 0; i < n; i++) {
        for (int j = c; j >= w[i]; j--) f[j] = max(f[j], f[j - w[i]] + v[i]);
    }
    for (int i = 0; i <= c; i++) ans = max(ans, f[i]);
    printf("%d\n", ans);
    return 0;
}
