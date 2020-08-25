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
    if((a%mod==0)&&(n==0)) return 0;
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
    Int a, b, c;
	char x, y;
	cin >> a >> x >> b >> y >> c;

    Int mod=1000000007;
    Int p=modpow(a,b,mod);
    Int q=modpow(b,c,mod-1);
    if(p<0) p+=mod;
    if(q<0) q+=mod; 

    Int fi=modpow(p,c,mod);
    Int af=modpow(a,q,mod);
    if(fi<0) fi+=mod;
    if(af<0) af+=mod;
    cout<<fi<<" "<<af<<endl;
    return 0;
}