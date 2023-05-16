#include<cstdio>
#include<cmath>
#include<algorithm>
#define maxn 100005

//用数组模拟线段树
struct Tree{
  int a[maxn];
  void add(int L,int R,int x) {
    for (int i=L;i<=R;i++) {
      a[i]+=x;
    }
  }
  int query(int x) {
    return a[x]; 
  }
  void debug() {
    printf("debug: ");
    for (int i=1;i<=5;i++) printf("%d ",a[i]);
    printf("\n");
  }
}f;

int n,m,block_size,maxai;
int a[maxn],block[maxn];
struct question {
  int l,r,a,b,id,ans;
  question() {}
  question(int l,int r,int a,int b,int id) {
    this->l=l;
    this->r=r;
    this->a=a;
    this->b=b;
    this->id=id;
  }
  //如果在同个块，按照r排序，否则按照块号排序
  bool operator <(const question y) {
    if (block[l]==block[y.l]) return r<y.r;
    return block[l]<block[y.l];
  }
}q[maxn];

int nowL,nowR;
void dec(int x) {
  f.add(x,maxai,-1);
}
void add(int x) {
  f.add(x,maxai,1);
}
int main() {
  scanf("%d%d",&n,&m);
  block_size=sqrt(n);
  for (int i=1;i<=n;i++) {
    block[i]=i/block_size+1;
  }
  for (int i=1;i<=n;i++) {
    scanf("%d",&a[i]);
    if (maxai<a[i]) maxai=a[i];
  }
  for (int i=1,l,r,a,b;i<=m;i++) {
    scanf("%d%d%d%d",&l,&r,&a,&b);
    q[i] = question(l,r,a,b,i);
    if (b>maxai) maxai=b;
  }
  std::sort(q+1,q+1+n);
  nowL=nowR=1;
  add(a[1]);
  for (int i=1;i<=m;i++) {
    while (nowL<q[i].l) dec(a[nowL++]);
    while (nowL>q[i].l) add(a[--nowL]);
    while (nowR>q[i].r) dec(a[nowR--]);
    while (nowR<q[i].r) add(a[++nowR]);
    q[i].ans=f.query(q[i].b)-f.query(q[i].a-1);
  }
  std::sort(q+1,q+1+n,
      [](question x,question y)->bool {return x.id<y.id;}
      );
  for (int i=1;i<=m;i++) {
    printf("%d\n",q[i].ans);
  }
  return 0;
}
