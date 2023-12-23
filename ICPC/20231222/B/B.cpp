#include<cstdio>

int x1,y1,x2,y2;
int pow(int x) {
	return x*x;
}
int main() {
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	printf("%d\n",pow(x2-x1)+pow(y2-y1));
	return 0;
}
