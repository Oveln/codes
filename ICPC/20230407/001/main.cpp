#include <cstdio>

int n, ax, ay, bx, by, ans;
int abs(int x) {
    if (x < 0) return -x;
    return x;
}
int calc1(int x) {
    if (x & 1) return x / 2 + 1;
    return x / 2;
}
int min(int x, int y) {
    if (x < y) return x;
    return y;
}
void swap(int &x, int &y) {
    int c = x;
    x     = y;
    y     = c;
}
int main() {
    scanf("%d%d%d%d%d", &n, &ax, &ay, &bx, &by);
    if (bx < by) swap(bx, by), swap(ax, ay);
    int c = (bx - by) - (ax - ay);
    ax += c / 2, ay -= c / 2, ans += c / 2;
    if ((ax - ay) != (bx - by)) {
        ans++;
        if ((ax - ay) < (bx - by))
            ans += min(abs(ax + 1 - bx), abs(ay - 1 - by));
        else
            ans += min(abs(ax - 1 - bx), abs(ay + 1 - by));
    }
    printf("%d\n", ans);
    return 0;
}
