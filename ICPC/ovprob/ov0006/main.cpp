//求长度为n的字符串中，114514作为子序列出现的次数

#include<cstdio>
#include<string>
#include<iostream>
#include<random>
using namespace std;

const char target[10] = "114514";
int n;
string s;
long long f[1005][10],ans;
int main() {
    cin>>s;
    for (int i=0;i<s.length();i++) {
        if (s[i]==target[0]) f[i][0]=1;
    }
    for (int i=0;i<s.length();i++) {
        for (int k=1;k<6;k++) {
            if (s[i]==target[k]) {
                for (int j=0;j<i;j++) {
                    f[i][k]+=f[j][k-1];
                }
            } 
        }
    }
    for (int i=0;i<s.length();i++) {
        ans+=f[i][5];
    }
    cout<<ans<<endl;
    return 0;
}