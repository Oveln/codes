#include<cstdio>

long long a,b,c,n;
long long calc(long long x) {
	long long ret =0;
	while (x) ret+=x%10,x/=10;
	return ret;
}
int main() {
	scanf("%lld",&n);
	for (int i=1;i<=n;i++) {
		scanf("%lld%lld",&a,&b);
		long long sa=calc(a),sb=calc(b);
		bool flg=0,x=a%sb==0,y=b%sa==0;
		if (x) flg=1;
		if (y) flg=0;
		if ((x&&y)||(!x&&!y)) {
			if (a>b) flg=1;else flg=0;
		}
		printf("%c",flg?'A':'B');
		if (i!=n) printf("\n");
	}
	return 0;
}