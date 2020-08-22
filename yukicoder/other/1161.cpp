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

Int modpow(long long a, long long n, long long mod) {
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
    Int a,b,c; cin>>a>>b>>c;
    Int ans=0;
    for(int i=1; i<=c; i++) ans+=modpow(i,b,c);
    Int pn=ans*(a/c);
    pn%=c;
    if(pn<0) pn+=c;
    for(int i=1; i<=a%c; i++){
        pn+=modpow(i,b,c);
    }
    pn%=c;
    if(pn<0) pn+=c;
    cout<<pn<<endl;
    return 0;
}