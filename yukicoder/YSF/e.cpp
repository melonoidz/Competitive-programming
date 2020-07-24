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
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;

Int modinv(Int a, Int m) { // (a/b mod.MOD) a*modinv(b,MOD)%MOD  
    long long b = m, u = 1, v = 0;
    while (b) {
        Int t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    Int p,n; cin>>p>>n;
    vector<Int> a(n,0);
    for(Int i=0; i<n; i++) cin>>a[i];
    string s; cin>>s;
    Int ans=a[0];
    for(Int i=0; i<n-1; i++){
        char op=s[i];
        if (op=='+'){
            ans+=a[i+1];
            
        }
        else if(op=='-'){
            ans-=a[i+1];
        }
        else if(op=='*'){
            ans*=a[i+1];
        }
        else{
            ans%=p;
            ans*=modinv(a[i+1],p)%p;
        }
        ans%=p;
        if(ans<0) ans+=p;
        if(ans==0) ans+=p;
    }
    cout<<ans%p<<endl;
    return 0;
}