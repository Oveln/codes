#include <cstdio>
#include <cstring>
#define maxn 1005

// 男生从1到n编号，女生从1到m编号
int n, m;           // 男n个,女m个
int g[maxn][maxn];  // 邻接矩阵
int nowLnk[maxn];   // 右边对象当前匹配的左边对象
bool vis[maxn];     // dfs中是否访问，防环
int ans;

bool findCouple(int x) {
    for (int i = 1; i <= m; i++) {
        if (g[x][i] && !vis[i]) {
            vis[i] = 1;
            if (!nowLnk[i] || findCouple(nowLnk[i])) {
                nowLnk[i] = x;
                return true;
            }
        }
    }
    return false;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &g[i][j]);
        }
    }
    memset(nowLnk, 0, sizeof(nowLnk));
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        ans += findCouple(i);
    }
    printf("%d\n", ans);
    return 0;
}
