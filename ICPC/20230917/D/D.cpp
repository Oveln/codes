#include<cstdio>
#include<algorithm>
#define maxn 1000005
int n,m;
int fa[maxn],v[maxn];//v点的个数
long long ans;
bool vis[maxn];
int a[maxn],cnt;
int getfa(int x) {
	if (fa[x]==x) return x;
	return fa[x]=getfa(fa[x]);
}
int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) fa[i]=i,v[i]=1;
	for (int i=1,x,y;i<=m;i++) {
		scanf("%d%d",&x,&y);
		if (getfa(x)!=getfa(y)) {
			ans+=(long long)v[getfa(x)]*v[getfa(y)];
			v[getfa(y)]+=v[getfa(x)];
			fa[getfa(x)]=getfa(y);
		}
	}
	ans -= m;
	if (!ans) {
		for (int i=1;i<=n;i++) if (!vis[getfa(i)]) vis[getfa(i)]=1,a[++cnt]=v[getfa(i)];
		std::sort(a+1,a+1+cnt);
		ans+=(long long)a[1]*a[2];
	}
	printf("%lld",ans);
	return 0;
}
