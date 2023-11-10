#include<cstdio>

char lanqiao[8] = "lanqiao";
char s[255];
bool flg = true;
int main() {
	scanf("%s",s);
	for (int i=0;i<8;i++) {
		if (s[i]==lanqiao[i] || s[i]-'A'+'a' == lanqiao[i]) continue;
		flg = 0;
		break;
	}
	if (s[8]!='\0') flg=0;
	printf("%s",flg?"yes":"no");
	return 0;
}
