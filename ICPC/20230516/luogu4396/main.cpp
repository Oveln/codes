#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#define MAXN 100005

// 线段树结点
struct TreeNode {
    int sum, kinds;  // 数量和种类数
    TreeNode operator+(const TreeNode b) {
        return TreeNode{sum + b.sum, kinds + b.kinds};
    }
};
// 用数组模拟线段树
struct Tree {
    TreeNode a[2 * MAXN];
    int size;

    Tree(int x) : size(x) { memset(a, sizeof(a), 0); }
    TreeNode _query(int now, int L, int R, int QL, int QR) {
        if (L == QL && R == QR) {
            return a[now];
        }
        int mid = L + ((R - L) >> 1);
        if (QR <= mid)
            return _query(now * 2, L, mid, QL, QR);
        else if (QL > mid)
            return _query(now * 2 + 1, mid + 1, R, QL, QR);
        else
            return _query(now * 2, L, mid, QL, mid) +
                   _query(now * 2 + 1, mid + 1, R, mid + 1, QR);
    }
    // 查询L到R的数据
    TreeNode query(int L, int R) { return _query(1, 1, size, L, R); }

    void _set(int now, int L, int R, int pos, int value) {
        if (L == R && L == pos) {
            a[now].sum += value, a[now].kinds = a[now].sum > 0;
            return;
        }
        int mid = L + ((R - L) >> 1);
        if (pos <= mid)
            _set(now * 2, L, mid, pos, value);
        else
            _set(now * 2 + 1, mid + 1, R, pos, value);
        a[now] = a[now * 2] + a[now * 2 + 1];
    }
    void set(int pos, int value) { _set(1, 1, size, pos, value); }

} f(0);

int n, m, block_size, maxai;
int a[MAXN], block[MAXN];
struct question {
    int l, r, a, b, id, ans1, ans2;
    question() {}
    question(int l, int r, int a, int b, int id) {
        this->l  = l;
        this->r  = r;
        this->a  = a;
        this->b  = b;
        this->id = id;
    }
    // 如果在同个块，按照r排序，否则按照块号排序
    bool operator<(const question y) {
        if (block[l] == block[y.l]) return r < y.r;
        return block[l] < block[y.l];
    }
} q[MAXN];

int nowL, nowR;
void dec(int x, Tree* f) { f->set(x, -1); }
void add(int x, Tree* f) { f->set(x, 1); }
int main() {
    scanf("%d%d", &n, &m);
    f.size     = n;
    block_size = sqrt(n);
    for (int i = 1; i <= n; i++) {
        block[i] = i / block_size + 1;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (maxai < a[i]) maxai = a[i];
    }
    for (int i = 1, l, r, a, b; i <= m; i++) {
        scanf("%d%d%d%d", &l, &r, &a, &b);
        q[i] = question(l, r, a, b, i);
        if (b > maxai) maxai = b;
    }
    std::sort(q + 1, q + 1 + n);
    nowL = nowR = 1;
    add(a[1], &f);
    for (int i = 1; i <= m; i++) {
        while (nowL < q[i].l) dec(a[nowL++], &f);
        while (nowL > q[i].l) add(a[--nowL], &f);
        while (nowR > q[i].r) dec(a[nowR--], &f);
        while (nowR < q[i].r) add(a[++nowR], &f);
        auto ans  = f.query(q[i].a, q[i].b);
        q[i].ans1 = ans.sum, q[i].ans2 = ans.kinds;
    }
    std::sort(q + 1, q + 1 + n,
              [](question x, question y) -> bool { return x.id < y.id; });
    for (int i = 1; i <= m; i++) {
        printf("%d %d\n", q[i].ans1, q[i].ans2);
    }
    return 0;
}
