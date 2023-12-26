#include <cstdio>

const int maxn = 200005;
int n, Q, q, maxai;
int a[maxn];
// ans[i] 表示是否存在一个齿轮链，使得齿轮链的比例为i
// vis[i] 表示是否存在一个齿轮大小为i
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
    // 可以发现，如果 a 中存在一对齿轮a[i],a[j],满足a[i]/a[j] = k
    // 那么就可以把j放在第一个，i放在最后一个，中间放剩下的齿轮
    // 整个齿轮链的比例就是k
    for (int i = 1; i <= n; i++) {
        for (int j = 2; j * a[i] <= maxai; j++)
            // 枚举倍数j
            // 因为a[i]必然存在，则如果存在一个齿轮大小为j*a[i]，则ans[j]为真
            // 这个枚举方法会被卡，想想为什么，要怎么样不会被卡
            ans[j] |= vis[j * a[i]];
    }
    while (Q--) {
        scanf("%d", &q);
        // 如果q这个倍率合法
        printf("%s\n", ans[q] ? "YES" : "NO");
    }
    return 0;
}
