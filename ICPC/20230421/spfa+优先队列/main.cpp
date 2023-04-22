#include<cstdio>
#include<queue>
#include<cstring>
#define maxn 1505
#define maxe 5005

int n,m;
int dis[maxn],pree[maxn];
int lnk[maxe],nxt[maxe],edg[maxn],w[maxe],cnt[maxe];
struct node {
	int id,w;
	node(int x,int y) {
		id=x,w=y;
	}
	bool operator<(const node b)const {
		return b.w<w;
	}
};
std::priority_queue<node> que;
void dij(int start) {
	for (int i=1;i<=n;i++) {
		dis[i]=1000000000;
	}
	dis[start]=0;
	que.push(node(start,0));
}
int main() {
	scanf("%d%d",&n,&m);
	for (int i=1,x,y,z;i<=m;i++) {
		scanf("%d%d%d",&x,&y,&z);
		nxt[i]=edg[x],edg[x]=i,lnk[i]=y,w[i]=z;
	}
	for (int i=1;i<=n;i++) dij(i);
	for (int i=1;i<=m;i++) {
		printf("%d\n",cnt[i]);
	}
	return 0;
}