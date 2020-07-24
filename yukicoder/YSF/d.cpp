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
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,q; cin>>n>>q;
    vector<int> a(n,0);
    rep(i,n) cin>>a[i];
    vector<int> _xor(n+1,0);
    _xor[0]=0;
    for(int i=0; i<n; i++){
        _xor[i+1]=_xor[i]^a[i];
    }
    for(int i=0; i<q; i++){
        int l,r; cin>>l>>r;
        int xorl=_xor[l-1];
        int ans=_xor[r]^xorl;
        cout<<ans<<endl;
    }
    return 0;
}