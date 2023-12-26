#include <cstdio>
#define maxn 105

int n, m, t, ans;
int map[maxn][maxn];
int main() {
    scanf("%d%d", &n, &m);
    scanf("%d", &t);
    while (t--) {
        int r1, r2, c1, c2;
        scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
        for (int i = r1; i <= r2; i++)
            for (int j = c1; j <= c2; j++) {
                map[i][j] = 1;
            }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) ans += !map[i][j];
    printf("%d\n", ans);
    return 0;
}
