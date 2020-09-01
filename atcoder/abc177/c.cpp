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
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin>>n;
    vector<Int> a(n,0);
    rep(i,n) cin>>a[i];
    Int mod=1000000007;
    vector<Int> sa(n,0);
    sa[0]=a[0];
    for(int i=0; i<n-1; i++){
      sa[i+1]=sa[i]+a[i+1];
    }
    Int ans=0;
    for(int i=0; i<n; i++){
      Int tmp=(sa[n-1]-sa[i])%mod;
      tmp*=a[i]%mod;
      ans+=tmp;
      ans%=mod;
      if(ans<0) ans+=mod;
    }
    cout<<ans<<endl;
    return 0;
}