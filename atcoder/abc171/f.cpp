#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;
typedef pair<int, int> pint;
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int k; cin>>k;
    string s; cin>>s;
    Int mod=1000000007;
    Int ans=0;
    Int ls=s.size();
    Int tmp=1;
    for(Int i=ls+1; i<=ls+k; i++){
        tmp*=i;
    }
    ans=modpow(26,tmp,mod);
    if(ans<0) ans+=mod;
    cout<<ans<<endl;
    return 0;
}