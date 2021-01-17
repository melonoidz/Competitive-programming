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
 vc<int> a(1<<n,0);
 vc<int> fight(2<<17,0);
 rep(i,1<<n) 
 {
    cin>>a[i];
    fight[a[i]]=i;
    }
vc<int> ans(1<<n);
vc<int> now;
now=a;
for(int i=0; i<n; i++)
{
    vc<int> tmp;
    if(now.size()==2)
    {
        ans[fight[now[0]]]=i+1;
        ans[fight[now[1]]]=i+1;
        break;
    }
    for(int j=0; j<now.size(); j+=2)
    {
        if(now[j]<now[j+1])
        {
            tmp.push_back(now[j+1]);
            ans[fight[now[j]]]=i+1;
        }else
        {
            tmp.push_back(now[j]);
            ans[fight[now[j+1]]]=i+1;
        }
    }
    now=tmp;
}
    rep(i,1<<n) cout<<ans[i]<<endl;                                
    return 0;                                  
}