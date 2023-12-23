#include<cstdio>
#include<cstring>
#define maxLen 10005

int T,M,len;
int level[255];
char cstk[maxLen];
int nstk[maxLen],ns,cs;
char s[maxLen];
long long pow(long long a,long long b) {
	if (b==0) return 1;
	long long w = pow(a,b/2);
	if (b&1) return (w*w*a)%M;
	else return (w*w)%M;
}
void calc() {
	switch (cstk[cs]) {
		case '+':{
			nstk[ns-1] = ((long long)nstk[ns]+nstk[ns-1])%M;
			ns--;
			break;
		}
		case '-':{
			nstk[ns-1] = ((long long)nstk[ns-1]-nstk[ns]+M)%M;
			ns--;
			break;
		}
		case '*':{
			nstk[ns-1] = ((long long)nstk[ns-1]*nstk[ns]+M)%M;
			ns--;
			break;
		}
		case '^':{
			nstk[ns-1] = pow(nstk[ns-1],nstk[ns]);
			ns--;
			break;
		}
	}
}
void work(char c) {
	switch (c) {
		case '(':{
			cstk[++cs] = c;
			break;
		}
		case ')':{
			while (cstk[cs]!='(') {
				calc();
				cs--;
			}
			cs--;
			break;
		}
		case '-': 
		case '+':
		case '*':
		case '^':{
			while (level[cstk[cs]]>=level[c]) {
				calc();
				cs--;
			}
			cstk[++cs]=c;
			break;
		}
	}
}
int main() {
	level['(']=0;
	level['+']=level['-']=1;
	level['*']=2;
	level['^']=3;
	scanf("%d%d\n",&T,&M);
	while (T--) {
		ns=cs=len=0;
		memset(s,0,sizeof s);
		scanf("%s",s+1);
		s[0] = '(';
		while (s[len]) len++;
		s[len++] = ')';
		
		for (int i=0;s[i];i++) {
			if (s[i]>='0' && s[i]<='9') {
				int num = 0;
				while (s[i]>='0' && s[i]<='9') {
					num=num*10+s[i]-'0';
					i++;
				}
				i--;
				nstk[++ns] = num%M;
			} else {
				work(s[i]);
			}
		}
		printf("%d\n",nstk[ns]);
	}
	return 0;
}
