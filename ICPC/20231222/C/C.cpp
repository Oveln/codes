#include<cstdio>

int T;
long long x,y;
long long god(long long x) {
	while (x>9) {
		long long w = x, sum = 0;
		while (w) sum+=w%10,w/=10;
		x=sum;
	}
	return x;
}
int main() {
	scanf("%d",&T);
	while (T--) {
		scanf("%lld%lld",&x,&y);
		x = god(x);
		y = god(y);
		if (x>y) printf("x\n");
		else if (x<y) printf("y\n");
		else printf("xxxyyy\n");
	}
	return 0;
}
