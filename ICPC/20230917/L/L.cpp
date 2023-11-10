#include<cstdio>

int a,b,c,ans=2;
int max(int x,int y) {
	if (x>y) return x;return y;
}
int main() {
	scanf("%d%d",&a,&b);
	for (int i=1;i<=a;i++) {
		scanf("%d",&c);
		ans = max(ans,(c+b-1)/b);
	}
	printf("%d\n",ans);
	return 0;
}
