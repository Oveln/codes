#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#define maxn 10005

using namespace std;

std::map<string, int> a, b;
std::map<string, bool> c;
int r1, r2;
string e[maxn], f[maxn];
int n, m;
string s;

int min(int x, int y) {
    if (x < y) return x;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1, rank = 0; i <= n; i++) {
        cin >> s;
        if (!a[s]) a[s] = ++r1, e[r1] = s;
    }
    for (int i = 1, rank = 0; i <= m; i++) {
        cin >> s;
        if (!b[s]) b[s] = ++r2, f[r2] = s;
    }
    for (int i = 1; i <= max(r1, r2); i++) {
        if (e[i] != "" && !c[e[i]]) {
            c[e[i]] = 1;
            cout << e[i] << endl;
        }
        if (f[i] != "" && !c[f[i]]) {
            c[f[i]] = 1;
            cout << f[i] << endl;
        }
    }
    return 0;
}
