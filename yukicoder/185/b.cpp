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
    int mod=17;
    vector<Int> ans(1000010,0);
    ans[4]=1;
    Int tmp=0;
    for(int i=5; i<=1000010; i++){
        ans[i]=(tmp+ans[i-1])%mod;
        if(ans[i]<0) ans[i]+=mod;
        tmp=(ans[i]-ans[i-4])%mod;
        if(tmp<0) tmp+=mod;
    }
    int q; cin>>q;
    rep(i,q){
        Int n; cin>>n;
        cout<<ans[n]%mod<<endl;
    }
    return 0;
}