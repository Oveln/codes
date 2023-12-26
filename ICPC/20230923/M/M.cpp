#include <algorithm>
#include <cstdio>
#define maxn 5005

int T, n;
double ans, nowt;
struct pb {
    int a, b;
    double p;
    double calc() { return a * (1 - p) + (a + b) * (p); }
} a[maxn];
bool cmp(pb a, pb b) { return a.calc() < b.calc(); }
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d%d%lf", &a[i].a, &a[i].b, &a[i].p);
        }
        std::sort(a + 1, a + 1 + n, cmp);
        ans = nowt = 0;
        for (int i = 1; i <= n; i++) {
            nowt += a[i].calc();
            ans += nowt;
        }
        printf("%.12lf\n", ans);
    }
    return 0;
}
