#include <cstdio>
#define maxn 1005
#define maxC 1005

int n,c,w[maxn],v[maxn];
struct fdata {
  int x,pre,id;
}f[maxC];
int main() {
  scanf("%d%d",&n,&c);
  for (int i=0;i<n;i++) {
    scanf("%d%d",&w[i],&v[i]);
  }
  for (int i=1;i<=c;i++) f[i].x = -100000000;
  for (int i=0;i<n;i++) {
    for (int j=c;j>=w[i];j--)
      if (f[j-w[i]].x>=0 && f[j-w[i]].x+v[i]>f[j].x) {
        f[j]= {
          f[j-w[i]].x+v[i],
          j-w[i],
          i+1
        };
      }
  }
  if (f[c].x) {
    for (int i=c;i!=0;i=f[i].pre) printf("%d%c",f[i].id,f[i].pre?' ':'\n');
  } else printf("No\n");
  printf("%d\n",f[c].x);
  return 0;
}
