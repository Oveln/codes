#include <cstdio>
#include <iostream>
#include <random>
#include <string>
using namespace std;

int main() {
    // 生成随机数n，随后输出n个随机生成的长度在3~9之间的字符串
    std::random_device seed;
    std::ranlux48 engine(seed());
    std::uniform_int_distribution<> nrand(1, 100);
    std::uniform_int_distribution<> lrand(3, 9);
    int n = nrand(engine);
    printf("%d\n", n);
    for (int i = 1; i <= n; i++) {
        int len = lrand(engine);
        for (int j = 1; j <= len; j++) {
            printf("%c", nrand(engine) % 26 + 'a');
        }
        printf("\n");
    }
    return 0;
}