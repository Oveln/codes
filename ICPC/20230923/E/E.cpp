#include<cstdio>
#define maxn 100005

using namespace std;

int n,m;
int que[maxn],head;
bool vis[maxn],v[maxn];
int p[maxn];
int lnk[maxn],e[maxn*2],nxt[maxn*2],cnt;
int lnk1[maxn],e1[maxn*2],nxt1[maxn*2],cnt1;
int f[maxn];//f[i] is the shortest time to i from 1
void add_edge(int x,int y) { //add path x to y
	nxt[++cnt] = lnk[x];
	lnk[x] = cnt;
	e[cnt] = y;
}
void add_edge1(int x,int y) { //add path x to y
	nxt1[++cnt1] = lnk1[x];
	lnk1[x] = cnt1;
	e1[cnt1] = y;
}
bool dfs(int x,int value) {
	if (vis[x]) return 1;
	for (int i=lnk[x];i;i=nxt[i]) {
		if (!v[e[i]]) {
			v[e[i]] = 1;
			if (dfs(e[i],value)) {
				que[++que[0]] = x;
				vis[x] = 1;
				f[x] = value;
				v[e[i]] = 0;
				return vis[x] = 1;
			}
			v[e[i]] = 0;
		}
	}
	return 0;
}
int main() {
	scanf("%d%d",&n,&m);
	for (int i=2,x;i<=n;i++) {
		scanf("%d",&x);
		add_edge(i,x);
		add_edge(x,i);
		f[i] = -1;
	}
	for (int i=1,x,y;i<=m;i++) {
		scanf("%d%d",&x,&y);
		add_edge1(x,y);
		add_edge1(y,x);
	}
	que[++que[0]] = 1, vis[1] = 1;
	while (head<que[0]) {
		++head;
		for (int i=lnk1[que[head]];i;i=nxt1[i]) {
			if (!vis[e1[i]]) {
				v[e1[i]] = 1;
				dfs(e1[i],f[que[head]]+1);
				v[e1[i]] = 0;
			}
		}
	}
	for (int i=2;i<=n;i++) {
		printf("%d%c",f[i],i==n?'\n':' ');
	}
	return 0;
} 
