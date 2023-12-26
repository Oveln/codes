#include <cstdio>
int mo[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int cnt;

int calc(int x) {
    int ret = 0;
    while (x) {
        ret += x % 10;
        x /= 10;
    }
    return ret;
}
int getmo(int y, int m) {
    if (m != 2) return mo[m - 1];
    return mo[m - 1] + (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0));
}
int main() {
    for (int i = 1999; i <= 9999; i++) {
        for (int j = 1; j <= 12; j++) {
            int days = getmo(i, j);
            for (int k = 1; k <= days; k++) {
                if (calc(i) == (calc(j) + calc(k)))
                    printf("%d %d %d\n", i, j, k), cnt++;
            }
        }
    }
    printf("ans:%d\n", cnt);
    return 0;
}
