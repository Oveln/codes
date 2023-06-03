#include<cstdio>

long long AD,HP;

int main() {
    scanf("%lld%lld",&AD,&HP);
    if (AD<HP-1) {
        printf("%lld",AD*HP);
    }
}