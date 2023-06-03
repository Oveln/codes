// 求区间和：
#include<cstdio>

#define maxn 10005

struct Tree {
  int a[maxn],size;

  int __query(int now, int L, int R, int QL, int QR) {
    if (L==QL&&R==QR) return a[now];
    int mid = (L+R)>>1;
    if (mid>=R) return __query(now<<1, L, mid, QL, QR);
    if (mid<L) return __query(now<<1&1, mid+1, R, QL, QR);
    return __query(now<<1, L, mid, QL, mid) + __query(now<<1&1, mid+1, R, mid+1, QR);
  }
  //查询QL到QR的和
  int query(int QL,int QR) {
    return __query(1, 1, size, QL, QR);
  }

  void __change(int now, int L, int R, int x, int y) {
    if (L==R&&L==x) {
      a[now]=y;
      return;
    }
    int mid = (L+R)>>1;
    if (mid>=x) __change(now<<1, L, mid, x, y);
    if (mid<x) __change(now, mid+1, R, x, y);
    a[now] = a[now<<1]+a[now<<1&1];
  }
  //将x位置的值的改成y
  void change(int x,int y) {
    __change(1, 1, size, x, y);
  }
};

int main() {
  
}
