#include<cstdio>

int n;
int a[3];
void swap(int &x,int &y) {
	int z=x;
	x=y,y=z;
}
int main() {
	for (int i=0;i<3;i++) a[i]=1000001;
	scanf("%d",&n);
	for (int i=1,x;i<=n;i++) {
		scanf("%d",&x);
		for (int j=0;j<3;j++) if (x<a[j]) swap(x,a[j]);
		if (i>2) printf("%d%c",a[2],i==n?'\n':' ');
	}
	return 0;
}
