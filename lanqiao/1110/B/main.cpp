#include <cstdio>

int main() {
    int cnt = 26;
    for (int i = 'A'; i <= 'Z'; i++)
        for (int j = 'A'; j <= 'Z'; j++) {
            printf("%d\n", cnt);
            if ((++cnt) == 2022) printf("%c%c", i, j);
        }
    for (int i = 'A'; i <= 'Z'; i++)
        for (int j = 'A'; j <= 'Z'; j++)
            for (int k = 'A'; k <= 'Z'; k++) {
                if ((++cnt) == 2022) printf("%c%c%c", i, j, k);
            }
}
