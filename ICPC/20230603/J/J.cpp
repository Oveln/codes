#include<cstdio>
#include<vector>
#define LL long long

using namespace std;

const int maxn=100005;

struct SegmentNode {
    LL w,change_lazy,add_lazy;
};
struct SegmentTree {
    vector<SegmentNode> a;
    int size;
    void _build(int now,int L,int R,vector<LL>* b) {
        if (L==R) {
            a[now]={b->at(L),0,0};
            return;
        }
        int mid = (L+R)/2;
        _build(now*2,L,mid,b);
        _build(now*2+1,mid+1,R,b);
        a[now]={
            a[now*2].w+a[now*2+1].w,
            0,
            0
        };
    }
    void build(vector<LL> b) {
        size = b.size();
        a.resize(b.size()*4+1);
        _build(1,1,b.size()-1,&b);
    }
    void down_lazy(int x,int L,int R) {
        if (a[x].change_lazy!=0) {
            int mid=(L+R)/2,Lson=x*2,Rson=x*2+1;
            a[Lson]={
                a[x].change_lazy*(mid-L+1),
                a[x].change_lazy,
                0
            };
            a[Rson]={
                a[x].change_lazy*(R-mid),
                a[x].change_lazy,
                0
            };
            a[x].change_lazy=0;
        }
        if (a[x].add_lazy!=0) {
            int mid = (L+R)/2,Lson=x*2,Rson=x*2+1;
            a[Lson].add_lazy+=a[x].add_lazy;
            a[Rson].add_lazy+=a[x].add_lazy;
            a[Lson].w+=a[x].add_lazy*(mid-L+1);
            a[Rson].w+=a[x].add_lazy*(R-mid);
            a[x].add_lazy=0;
        }
    }
    LL _query(int now,int L,int R,int QL,int QR) {
        if (L==QL&&R==QR) {
            return a[now].w;
        }
        down_lazy(now,L,R);
        int mid = (L+R)/2;
        if (QR<=mid) return _query(now*2,L,mid,QL,QR);
        else if (QL>mid) return _query(now*2+1,mid+1,R,QL,QR);
        else return _query(now*2,L,mid,QL,mid)+_query(now*2+1,mid+1,R,mid+1,QR);
    }
    void _modify(int now,int L,int R,int ML,int MR,int x) {
        if (L==ML&&R==MR) {
            a[now].w=x*(R-L+1);
            if (L!=R) {
                a[now].change_lazy=x;
                a[now].add_lazy=0;
            }
            return;
        }
        down_lazy(now,L,R);
        int mid=(R+L)/2;
        if (MR<=mid) _modify(now*2,L,mid,ML,MR,x);
        else if (ML>mid) _modify(now*2+1,mid+1,R,ML,MR,x);
        else _modify(now*2,L,R,ML,mid,x),_modify(now*2+1,mid+1,R,mid+1,MR,x);
    }
    void _add(int now,int L,int R,int AL,int AR,int x) {
        if (L==AL&&R==AR) {
            a[now].w+=x*(R-L+1);
            if (L!=R) {
                a[now].add_lazy+=x;
            }
            return;
        }
        down_lazy(now,L,R);
        int mid=(R+L)/2;
        if (AR<=mid) _add(now*2,L,mid,AL,AR,x);
        else if (AL>mid) _add(now*2+1,mid+1,R,AL,AR,x);
        else _modify(now*2,L,R,AL,mid,x),_add(now*2+1,mid+1,R,mid+1,AR,x);
    }
    LL query(int L,int R) {
        return _query(1,1,size,L,R);
    }
    void modify(int L,int R,LL x) {
        _modify(1,1,size,L,R,x);
    }
    void add(int L,int R,LL x) {
        _add(1,1,size,L,R,x);
    }

};
struct Result {
    vector<pair<int,int>> k;//k[i]表示该点向下i层所管理的范围
}r[maxn];
int n,maxdep,Q;
int a[maxn],dep[maxn];
int pos[maxn];//单个点i在b[dep[i]]中的位置
vector<vector<LL>> b;
vector<SegmentTree> c;
vector<int> lnk[maxn];

int max(int x,int y) {
    if (x>y) return x;return y;
}
int dfs(int now,int deep) {//层数 返回值为当前最深深度
    while (b.size()<=deep) {
        b.push_back(vector<LL>({-1}));
    }
    b[deep].push_back(a[now]);
    pos[now]=b[deep].size()-1;
    dep[now]=deep;
    int maxdep=deep;
    vector<int> start;
    if (b.size()<=deep) b.push_back(vector<LL>());
    for (int i=deep+1;i<=b.size();i++) {
        start.push_back(b[i].size());
    }
    for (int i=lnk[now].size()-1;i>=0;i--) {
        if (!dep[lnk[now][i]]&&lnk[now][i]!=1) {
            maxdep = max(dfs(lnk[now][i],deep+1),maxdep);
        }
    }
    int down=maxdep-deep;
    for (int i=1,si,st;i<=down;i++) {
        if (b.size()<=i+deep) si=1; else si=b[i+deep].size();
        if (start.size()<=i) st=1; else st=start[i];
        r[now].k.push_back({st,si-1});
    }
    return maxdep;
}
int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    for (int i=1,u,v;i<n;i++) {
        scanf("%d%d",&u,&v);
        lnk[u].push_back(v);
        lnk[v].push_back(u);
    }
    maxdep=dfs(1,0);
    for (int i=0;i<=maxdep;i++) {
        c.push_back(SegmentTree());
        c[i].build(b[i]);
    }
    // for (int i=0;i<=maxdep;i++) {
    //     for (int j=0;j<b[i].size();j++) {
    //         printf("%lld ",b[i][j]);
    //     }
    //     printf("\n");
    //     printf("%lld\n",c[i].query(1,b[i].size()-1));
    // }
    scanf("%d",&Q);
    while (Q--) {
        int code;
        scanf("%d",&code);
        switch (code) {
            case 1:{
                int p,x;
                scanf("%d%d",&p,&x);
                c[dep[p]].modify(pos[p],pos[p],x);
                break;
            }
            case 2:{
                int p,k,x;
                scanf("%d%d%d",&p,&k,&x);
                auto f = r[p].k[k-1];
                if (f.first>f.second) break;
                c[dep[p]+k].modify(f.first,f.second,x);
                break;
            }
            case 3:{
                int p,k,x;
                scanf("%d%d%d",&p,&k,&x);
                auto f = r[p].k[k-1];
                if (f.first>f.second) break;
                c[dep[p]+k].add(f.first,f.second,x);
                break;
            }
            case 4:{
                int p;
                scanf("%d",&p);
                printf("%lld\n",c[dep[p]].query(pos[p],pos[p]));
                break;
            }
            case 5:{
                int p,k;
                scanf("%d%d",&p,&k);
                pair<int,int> f=r[p].k[k-1];
                printf("%lld\n",c[dep[p]+k].query(f.first,f.second));
                break;
            }
        }
    }
    return 0;
}