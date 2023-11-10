#include<cstdio>

long long x;
int ans;

int main() {
	scanf("%lld",&x);
	x-=1;
	while (x) x/=2,ans++;
	printf("%d\n",ans);
	return 0;
}
