#include<cstdio>
#include<string>
#include<iostream>

using namespace std;

int n;
string s;
int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        cin>>s;
        if (s.length()<=4) {
            printf("CAN\n");
        }else if (s.length()<=6) {
            printf("MAYBE\n");
        } else {
            printf("CANNOT\n");
        }
    }
    return 0;
}