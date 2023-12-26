// 生成长度在(200,1000)以内的由数字组成的字符串
#include <iostream>
#include <random>
#include <string>
using namespace std;

int main() {
    std::random_device seed;
    std::ranlux48 engine(seed());
    std::uniform_int_distribution<> nrand(200, 1000);
    std::uniform_int_distribution<> lrand(0, 9);
    int n = nrand(engine);
    string s;
    for (int i = 1; i <= n; i++) {
        s += lrand(engine) + '0';
    }
    cout << s << endl;
    return 0;
}
