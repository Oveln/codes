#include <cstdio>
#define maxn 5005

int T, ans;
char s[maxn];
int main() {
    scanf("%d", &T);
    while (T--) {
        ans = 0;
        scanf("%s", s);
        for (int i = 0; s[i]; i++) {
            int l = i, r = i + 1;
            while (s[l] == s[r]) {
                ans++;
                l--, r++;
                if (l < 0 || !s[r]) break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
