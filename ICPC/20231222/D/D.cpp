#include<cstdio>
#include<cstdlib>
#define maxn 100005

int T,n;
char s[maxn],p[255];
long long ans;
int main() {
	p['A']='T',p['T']='A',p['C']='G',p['G']='C';
	scanf("%d",&T);
	while (T--) {
		ans = 0;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) s[i]=0;
		for (int i=1;i<=n;i++) {
			while (s[i]<'A' || s[i]>'Z') s[i]=getchar();
			if (s[i]!='A' && s[i]!='T' && s[i]!='C' &&s[i]!='G') ans = -1;
		}
		if (ans != -1) {
			for (int i=1;i<=n;i++) {
				if (p[s[i]] == s[n-i+1]) ans+=i;
			}
			printf("%lld\n",ans);
		} else printf("0\n");
	}
	return 0;
}
