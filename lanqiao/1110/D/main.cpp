#include<cstdio>

int cnt,cc;
int a[30] = {99, 22, 51, 63, 72, 61, 20, 88, 40, 21, 63, 30, 11, 18, 99, 12, 93, 16, 7, 53, 64, 9, 28, 84, 34, 96, 52, 82, 51, 77};
int main() {
	for (int i=0;i<30;i++) {
		for (int j=i+1;j<30;j++) {
			if (a[i]*a[j]>=2022) printf("%d %d\n",i,j),cnt++;
			cc++;
		}
	}
	printf("%d\n",cnt);
	printf("%d\n",cc);
	return 0;
}
