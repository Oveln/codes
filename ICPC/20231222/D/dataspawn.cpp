#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
    // ���������������������
    srand(time(0));
    // ���ɲ�������������
    int T = rand() % 5 + 1;
    cout << T << endl;
    while (T--) {
        // ����DNA���еĳ���
        int n = (long long)(rand() * rand()) % 100000 + 1;
        cout << n << endl;
        // ����DNA����
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
