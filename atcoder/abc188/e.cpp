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
 int N,M; cin>>N>>M;
 vc<int> A(N,0); 
 rep(i,N) cin>>A[i];
 vc<vc<int>> G(N);
 rep(i,M){
     int x,y; cin>>x>>y;
     x--, y--;
     G[y].push_back(x);
 }     
vc<int> dp(N,1e10);
 //dp[i]=min(dp[j] <j in i>)
 for(int i=0; i<N; i++){
     for(auto t: G[i]){
         dp[i]=min(dp[i],A[t]);
         dp[i]=min(dp[i],dp[t]);
     }
 }                            
 int res=-1e9;
 for(int i=0; i<N; i++){
     res=max(res,A[i]-dp[i]);
 }      
 cout<<res<<endl;                
}