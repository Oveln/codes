#include<cstdio>

int w,n;
int main() {
	scanf("%d%d",&w,&n);
	w-=1;
	w = (w+n)%7;
	printf("%d\n",w+1);
	return 0;
}