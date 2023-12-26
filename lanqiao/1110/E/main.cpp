#include <cstdio>
#define N 30
#define M 60

int fa[N * M + 5], cnt[N * M + 5];
int ans;
int flg[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int map[35][65];
inline int calc(int x, int y) { return (x - 1) * M + y; }
inline bool check(int x, int y) {
    if (x < 1 || y < 1 || x > N || y > M) return false;
    return true;
}
int getfa(int x) {
    if (fa[x] == x) return x;
    return fa[x] = getfa(fa[x]);
}
int getch() {
    char ch = getchar();
    while (ch != '0' && ch != '1') ch = getchar();
    return ch == '1';
}
int main() {
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) {
            map[i][j]       = getch();
            fa[calc(i, j)]  = calc(i, j);
            cnt[calc(i, j)] = map[i][j];
        }
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) {
            if (!map[i][j]) continue;
            for (int k = 0; k < 4; k++) {
                int fx = i + flg[k][0], fy = j + flg[k][1];
                if (!map[fx][fy] || !check(fx, fy) ||
                    getfa(calc(i, j)) == getfa(calc(fx, fy)))
                    continue;
                cnt[getfa(calc(i, j))] += cnt[getfa(calc(fx, fy))];
                fa[getfa(calc(fx, fy))] = getfa(calc(i, j));
            }
        }
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) {
            printf("%d%c", cnt[calc(i, j)], j == M ? '\n' : ' ');
            if (ans < cnt[getfa(calc(i, j))]) ans = cnt[getfa(calc(i, j))];
        }
    printf("%d\n", ans);
    return 0;
}
