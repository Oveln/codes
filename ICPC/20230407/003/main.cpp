#include<cstdio>
#include<cstring>
#define maxlen 45

struct BigInt {
  int a[maxlen];
  BigInt() {
    memset(a,0,sizeof(a));
  }
  BigInt(int x) {
    memset(a,0,sizeof(a));
    a[0] = 0;
    while (x!=0) a[++a[0]]=x%10,x/=10;
  }
  BigInt operator *(const BigInt b) {
    BigInt c(0);
    for (int i=1;i<=a[0];i++)
      for (int j=1;j<=b.a[0];j++) {
        c.a[i+j-1] += a[i]*b.a[j];
        c.a[i+j]+=c.a[i+j-1]/10,c.a[i+j-1]%=10;
      }
    while (c.a[c.a[0]+1]) c.a[0]++;
    return c;
  }
  bool operator <(const BigInt b) {
    if (a[0]!=b.a[0]) return a[0]<b.a[0];
    for (int i=a[0];i>=1;i--) if (a[i]!=b.a[i]) return a[i]<b.a[i];
    return 0;
  }
  BigInt add(int x) {
    BigInt ret = *this;
    for (int i=a[0];i>=1;i--) ret.a[i+1] = ret.a[i];
    ret.a[1] = x;
    ret.a[0]++;
    return ret;
  }
} f[maxlen][10],ans;
int n,k,a[maxlen];
inline int getaint() {
  char ch = getchar();
  while (ch>'9'||ch<'0') ch=getchar();
  return ch-'0';
}
int main() {
  scanf("%d%d",&n,&k);
  for (int i=1;i<=n;i++) {
    a[i]=getaint();
    f[i][0] = f[i-1][0].add(a[i]);
  }
  for (int i=1;i<=n;i++) {
    for (int j=1;j<=k;j++) {
      BigInt b(a[i]);
      for (int q=i-1;q>=j;q--) {
        BigInt nul = f[q][j-1]*b;
        if (f[i][j] < nul) f[i][j] = nul;
        b.a[++b.a[0]] = a[q];
      }
    }
  }
  ans = f[n][k];
  for (int i=ans.a[0];i>0;i--) {
    printf("%d",ans.a[i]);
  }
  return 0;
}
