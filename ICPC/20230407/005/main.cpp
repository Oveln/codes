#include<cstdio>
#define maxn 105

int n,m,a[maxn][maxn];
int fa[maxn*maxn],sum[maxn*maxn],ans;
int max(int x,int y) {
  if (x>y) return x;return y;
}
int calc(int x,int y) {
  return (x-1)*n+y;
}
int getfa(int x) {
  if (fa[x]==x) return x;
  return fa[x]=getfa(fa[x]);
}
int main() {
  scanf("%d%d",&n,&m);
  for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++) {
      scanf("%d",&a[i][j]);
      fa[calc(i,j)]=calc(i,j);
      sum[calc(i,j)] = a[i][j];
    }
  for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++) {
      if (!a[i][j]) continue;
      int now = calc(i,j),l=calc(i,j-1),u=calc(i-1,j);
      if (a[i-1][j]) if (getfa(now)!=getfa(u)) {
        sum[getfa(now)] += sum[getfa(u)];
        fa[getfa(u)] = getfa(now);
      }
      if (a[i][j-1]) if (getfa(now)!=getfa(l)) {
        sum[getfa(now)] += sum[getfa(l)];
        fa[getfa(l)] = getfa(now);
      }
    }
  for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++) {
      //printf("%d ",sum[getfa(calc(i,j))]);
      if (sum[getfa(calc(i,j))] == m) ans = 1;
    }
  printf("%s",ans?"YES":"NO");
  return 0;
}
