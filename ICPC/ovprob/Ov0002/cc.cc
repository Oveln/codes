#include <algorithm>
#include <iostream>
#include <random>

#include "testlib.h"
using namespace std;

const int maxn = 100000;
int main(int argc, char* argv[]) {
    setName("Interactor A+B");
    registerInteraction(argc, argv);
    // 自动生成两个随机整数
    rnd.setSeed(time(NULL));
    std::random_device rd;
    std::mt19937 rng(rd());
    std::random_device seed;
    std::ranlux48 engine(seed());
    std::uniform_int_distribution<> nrand(1, maxn);
    int n   = maxn;
    int ans = nrand(engine), pos = nrand(engine);
    // 本程序的输出将作为用户程序的输入
    printf("%d\n", n);
    for (int i = 1, x; i <= n; i++) {
        x = nrand(engine);
        printf("%d %d ", x, x);
        if (i == pos) printf("%d ", ans);
    }
    int c;
    // 用户程序的最后输出将作为本程序的输入
    cin >> c;
    // 对比用户结果和预期结果
    if (c != ans)
        quitf(_wa, "错喽,应该是%d，但结果是%d", ans,
              c);  // 输出错误的具体信息,便于做题者调试
    else
        quitf(_ok, "正确的");
}
