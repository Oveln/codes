#include<cstdio>
#include<string>
#include<iostream>

using namespace std;

struct node {
	char ch;
	int nxt;
}a[505];
int n;
string s,c,d;
int main() {
	cin>>s;
	a[1].ch='@',a[1].nxt=2;
	for (int i=0;i<s.length();i++) {
		a[i+2].ch=s[i],a[i+2].nxt=i==s.length()-1?0:i+3;
	}
	scanf("%d",&n);
	for (int k=1,x,y;k<=n;k++) {
		cin>>x>>y>>c>>d;
		x++,y++;
		int now=1,anow,bnow,canow,cbnow;
		for (int i=1;i<x-1;i++) now=a[now].nxt;
		anow=now,canow=a[now].nxt;
		for (int i=1;i<=y-x+1;i++) now=a[now].nxt;
		bnow=a[now].nxt,cbnow=now;
		a[anow].nxt=bnow;
		int cnt=0;
		now=1;
		while (1) {
			if (a[now].nxt==0) {
				a[now].nxt=canow,a[cbnow].nxt=0;
				break;
			}
			bool ff=0;
			if (a[now].ch==c[cnt]) cnt++,ff=1; else cnt=0;
			int qnow = now;
			if (cnt==c.length()&&ff) {
				qnow=a[now].nxt;
				for (int i=0;i<d.length();i++) {
					if (a[qnow].ch!=d[i]) {cnt=0;break;}
					qnow=a[qnow].nxt;
				}
			}
			if (cnt==c.length()&&ff) {
				a[cbnow].nxt=a[now].nxt,a[now].nxt=canow;
				break;
			}
			now=a[now].nxt;
		}
		
	}
	for (int i=1;i!=0;i=a[i].nxt) if (a[i].ch!='@')printf("%c",a[i].ch);
	return 0;
}