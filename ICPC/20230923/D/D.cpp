#include<cstdio>
#define maxn 505

int T;
int n;
int ma[maxn][maxn];
long long x,y,z;
int main() {
	scanf("%d",&T);
	while (T--) {
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) {
			scanf("%d",&ma[i][j]);
			if (ma[i][j]<0) z+=ma[i][j];
		}
		for (int i=1;i<=n;i++) {
			int min = 10000000;
			for (int j=1;j<=n;j++) {
				if (min>ma[i][j]) min=ma[i][j];
			}
			if (min>0) x+=min;
		}
		for (int j=1;j<=n;j++) {
			int min = 10000000;
			for (int i=1;i<=n;i++) {
				if (min>ma[i][j]) min=ma[i][j];
			}
			if (min>0) y+=min;
		}
		printf("%lld\n",(x<y?x:y)+z);
	}
	return 0;
}
