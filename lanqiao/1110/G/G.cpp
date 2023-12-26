#include <cstdio>
#define maxn 105
#define pow(x) ((x) * (x))

int W, H, n, R, ans;
struct t {
    int x, y;
} a[maxn];
bool check(t node, int x, int y) {
    return (pow(node.x - x) + pow(node.y - y)) <= pow(R);
}
int main() {
    scanf("%d%d%d%d", &W, &H, &n, &R);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &a[i].x, &a[i].y);
    }
    for (int i = 0; i <= W; i++)
        for (int j = 0; j <= H; j++) {
            for (int k = 1; k <= n; k++) {
                if (check(a[k], i, j)) {
                    ans++;
                    break;
                }
            }
        }
    printf("%d\n", ans);
    return 0;
}
