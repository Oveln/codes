#include<cstdio>
#include<cmath>

const int maxn = 25;
int n,k,n2,a[maxn],ans;

bool check(int x) { // 计算x中的1的个数是否等于k,如果是，返回true,否则返回false
  int cnt = 0;
  while (x!=0) {
    if (x%2==1) cnt++;
    x/=2;
  }
  return cnt==k;
}
int calc(int x) { // 计算x情况对应的a数组中的几个数相加的和
  int i=0,sum=0;
  while (x!=0) {
    if (x%2==1) sum+=a[i]; 
    i++,x/=2;
  }
  return sum; 
  // for (int i=0;x!=0;x/=2,i++) {
  //   if (x%2==1) sum+=a[i];
  // }
}
bool is_prime(int x) { //检查x是否是质数，是质数返回true,不是返回false
  if (x==1) return 0;
  int sqx = sqrt(x);
  for (int i=2;i<=sqx;i++) {
    if (x%i==0) return 0;
  }
  return 1;
}
int main() {
  scanf("%d%d",&n,&k);
  for (int i=0;i<n;i++) {
    scanf("%d",&a[i]);
  }
  n2 = 1;
  for (int i=0;i<n;i++) n2 *=2;
// 枚举情况
  for (int i=0;i<n2;i++) {
    if (check(i)) {
      int sum = calc(i);
      if (is_prime(sum)) ans++;
    }
  }
  printf("%d\n",ans);
  return 0;
}
