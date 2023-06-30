#include<cstdio>
#include<random>
#include<fstream>

char cmd[1005];
int now;
void swap(int &x,int &y) {
	int t=x;x=y;y=t;
}
int main() {	
	std::random_device seed;
	std::ranlux48 engine(seed());
	std::uniform_int_distribution<> nrand(1,100000),trand(0,1000),arand(0,24);
	for (int p=0;p<10;p++) {
		std::ofstream file("data"+std::to_string(p)+".in");
		int n=nrand(engine);
		file<<n<<'\n';
		if (p!=9) now=0;
		for (int i=0;i<n;i++) {
			int a=arand(engine),b=arand(engine);
			if (a<b) swap(a,b);
			now+=a;
			int t=trand(engine)%(now);
			now-=t;
			file<<t<<' '<<a<<' '<<b<<'\n';
		}
		file.close();
		sprintf(cmd,"main.exe <data%d.in >data%d.out",p,p);
		system(cmd);
	}
}
