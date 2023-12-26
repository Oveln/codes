#include <cstdio>
#include <string>

int T;
std::string tran(int x) {
    char c1 = 'w', c_1 = 'm';
    if (x < 0) {
        x  = -x;
        c1 = 'm', c_1 = 'w';
    }
    int now = 0;
    if (x == 0) return std::string("b");
    std::string ret("");
    while (x) {
        int w = x % 3;
        x /= 3;
        switch (w) {
            case 0: {
                ret = ret + 'b';
                break;
            }
            case 1: {
                ret = ret + c1;
                break;
            }
            case 2: {
                ret = ret + c_1;
                x++;
                break;
            }
        }
    }
    return ret;
}
int main() {
    scanf("%d", &T);
    int x;
    while (T--) {
        scanf("%d", &x);
        std::string s = tran(x);
        for (int i = s.length() - 1; i >= 0; i--) putchar(s[i]);
        putchar('\n');
    }
    return 0;
}