#include <cstdio>

int n, m;
int fa[100005], map[100005];
bool star[100005], vis[100005];
int ans, ansstar;
inline int getfa(int x) {
    if (fa[x] == x) return x;
    return fa[x] = getfa(fa[x]);
}
int calc(int x, int y) { return (x - 1) * m + y; }
int getint() {
    char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    return ch - '0';
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n * m; i++) fa[i] = i;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            map[calc(i, j)] = getint();
            if (map[calc(i, j)]) {
                if (i - 1 > 0 && map[calc(i - 1, j)])
                    fa[getfa(calc(i, j))] = getfa(calc(i - 1, j));
                if (j - 1 > 0 && map[calc(i, j - 1)])
                    fa[getfa(calc(i, j))] = getfa(calc(i, j - 1));
            }
        }
    }
    for (int i = 1; i <= n * m; i++) getfa(i);
    for (int i = 1; i <= n * m; i++) {
        if (map[i] && !vis[getfa(i)]) vis[getfa(i)] = 1, ans++;
        if (map[i] > 1 && !star[getfa(i)]) ++ansstar, star[getfa(i)] = 1;
    }
    printf("%d %d", ans, ansstar);
    return 0;
}