#include<cstdio>
int a,b,n,ans;
int abs(int x) {
	if (x<0) return -x;
}
int main(){
	scanf("%d%d%d",&a,&b,&n);
	for (int i=1;i<=n;i++) {
		if (a%i==0&&b%(n-i)==0) {
			if (abs(n-ans-ans)>abs(n-i-i)) ans=i;
		}
	}
	if (ans==0) printf("No Solution");else printf("%d %d",ans,n-ans);
	return 0;
}