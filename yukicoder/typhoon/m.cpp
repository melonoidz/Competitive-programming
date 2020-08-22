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
    Int n; cin>>n;
    Int mod=1000000007;
    vector<Int> dp(n+1,0);
    dp[0]=1;dp[1]=0; dp[2]=3;
    for(int i=2; i<n; i++){
        dp[i+1]=modpow(3,i,mod)-dp[i]%mod;
        dp[i+1]%=mod;
        if(dp[i+1]<0) dp[i+1]+=mod;
    }
    cout<<dp[n]<<endl;
    return 0;
}