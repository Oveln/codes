#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
    // 设置随机数生成器的种子
    srand(time(0));
    // 生成测试用例的数量
    int T = rand() % 5 + 1;
    cout << T << endl;
    while (T--) {
        // 生成DNA序列的长度
        int n = (long long)(rand() * rand()) % 100000 + 1;
        cout << n << endl;
        // 生成DNA序列
        for (int i = 0; i < n; ++i) {
            int x = rand() % 4;
            if (x == 0)
                cout << 'A';
            else if (x == 1)
                cout << 'C';
            else if (x == 2)
                cout << 'G';
            else
                cout << 'T';
        }
        cout << endl;
    }
    return 0;
}
