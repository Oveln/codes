#include<cstdio>
#include<iostream>
#include<queue>
#include<string>

int n,c,scn;
struct sc {
	int n,id;
	bool operator<(const sc b)const {
		if (n==b.n) return id>b.id;else return c-n<c-b.n;
	}
}st[250005];
int stn,maxst,ans;
std::priority_queue<sc> scs;
std::string name[5005];
int cnt[5005];
struct data {
	int n,id;
	bool operator <(const data b)const {
		return n<b.n;
	}
};
std::priority_queue<data> que;
int main() {
	std::cin>>n>>c;
	for (int i=1;i<=n;i++) {
		data s;
		std::cin>>name[i]>>s.n;
		s.id=i;
		que.push(s);
	}
	while (!que.empty()) {
		data now=que.top();que.pop();
		if (now.n>=c) {
			ans+=(now.n-que.top().n)/c+1;
			cnt[now.id]+=(now.n-que.top().n)/c+1;
			now.n-=((now.n-que.top().n)/c+1)*c;
			if (now.n) que.push(now);
		} else {
			cnt[now.id]++;
			if (now.n<c) {
				if (scs.empty()||c-scs.top().n<now.n) {
					sc scc;
					scc.id=++scn,scc.n=now.n;
					scs.push(scc);
					ans++;
				} else {
					stn=1;st[1]=scs.top(),scs.pop();
					int sec = 1;
					while (!scs.empty()&&c-scs.top().n>=now.n) {
						st[++stn]=scs.top(),scs.pop();
						if (st[stn].id<st[sec].id) sec=stn;
					}
					st[sec].n+=now.n;
					for (int i=1;i<=stn;i++) {
						if (st[i].n!=c) scs.push(st[i]);
					}
				}
			}
		}
	}
	for (int i=1;i<=n;i++) {
		std::cout<<name[i]<<" "<<cnt[i];
		printf("\n");
	}
	printf("%d",ans);
	return 0;
}