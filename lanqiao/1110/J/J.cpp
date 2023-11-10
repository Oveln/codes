#include<cstdio>
#define maxn 105

int flg[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int n,m,ans;
int mem[maxn][maxn],map[maxn][maxn];
inline bool check(int x,int y) {
	return (x>0&&x<=n)&&(y>0&&y<=m);
}
int dfs(int x,int y) {
	if (mem[x][y]!=-1) return mem[x][y];
	int ret = 1;
	for (int k=0,fx,fy;k<4;k++) {
		fx=x+flg[k][0],fy=y+flg[k][1];
		if (!check(fx,fy) || map[fx][fy]>=map[x][y]) continue;
		if (ret<dfs(fx,fy)+1) ret = dfs(fx,fy)+1;
	}
	return mem[x][y]=ret;
}
int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) {
		scanf("%d",&map[i][j]);
		mem[i][j] = -1;
	}
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) {
		if (ans<dfs(i,j)) ans = dfs(i,j);
	}
	printf("%d\n",ans);
	return 0;
}
