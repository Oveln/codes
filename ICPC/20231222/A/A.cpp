#include <cstdio>

int n;
int main() {
    scanf("%d", &n);
    if (n > 6 && n < 11)
        printf("zao shang hao");
    else if (n > 10 && n < 14)
        printf("zhong wu hao");
    else if (n > 13 && n < 18)
        printf("xia wu hao");
    else if (n > 17 && n < 22)
        printf("wan shang hao");
    else
        printf("zzz");
    return 0;
}
