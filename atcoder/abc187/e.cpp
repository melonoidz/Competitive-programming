#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define int ll
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
using pi=pair<int,int>;
using vi=vc<int>;
using uint=unsigned;
using ull=unsigned long long;
int popcount(signed t){
return __builtin_popcount(t);
}
int popcount(ll t){
return __builtin_popcountll(t);
}
bool ispow2(int i){
return i&&(i&-i)==i;
}
ll mask(int i){
return (ll(1)<<i)-1;
}
int lcm(int a, int b)
{
return a / __gcd(a, b) * b;
}
signed main(){
cin.tie(0);
ios::sync_with_stdio(0);
cout<<fixed<<setprecision(20);
int n; cin>>n;
vc<vc<int>> G;
G.resize(n);
vc<int> a(n-1),b(n-1);
rep(i,n-1){
    cin>>a[i]>>b[i];
    a[i]--, b[i]--;
    G[a[i]].push_back(b[i]);
    G[b[i]].push_back(a[i]);
}
vc<int> p(n,-1);
vc<vc<int>> ch(n);
queue<int> q;
q.push(0);
vc<int> bfs;
while(!q.empty()){
    int v= q.front();
    q.pop();
    bfs.push_back(v);
    for(auto w: G[v]){
        if(w!=p[v]){
            //先祖じゃないなら
            p[w]=v;
            ch[v].push_back(w);
            q.push(w);
        }
    }
}

int Q; cin>>Q;
int sum=0;
vc<int> c(n,0);    
while(Q--){
    int t,e,x; cin>>t>>e>>x;
    e--;
    int A,B;
    if(t==1){
        A=a[e];
        B=b[e];
    }
    else if(t==2){
        A=b[e];
        B=a[e];
    }
    if(B==p[A]){
        c[A]+=x;
        //aの親がbである(bfsで順次定まる)
    }else{
        sum+=x;
        c[B]-=x;
    }
}
for(auto j : bfs){
    for(auto w: ch[j]){
        c[w]+=c[j];
    }
}
for(int i=0; i<n; i++) cout<<sum+c[i]<<endl;
return 0;
//chは必要．Gだと双方に辺があるため
}