#include<cstdio>

int x,n;
int main() {
	scanf("%d%d",&x,&n);
	x-=1;
	x = (x+n)%7;
	printf("%d\n",x+1);
	return 0;
}
