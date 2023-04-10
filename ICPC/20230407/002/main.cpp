#include<cstdio>
#define maxn 1005

int n,m,T;
int a[maxn][maxn];
int main() {
  scanf("%d%d%d",&n,&m,&T);
  for (int i=1;i<=T;i++) {
    int c,x;
    scanf("%d%d",&c,&x);
    if (c==1) for (int j=1;j<=m;j++) a[x][j]=i;
    if (c==2) for (int j=1;j<=n;j++) a[j][x]=i;
  }
  for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++) 
      printf("%d%c",a[i][j],j==m?'\n':' ');
  return 0;
} 
