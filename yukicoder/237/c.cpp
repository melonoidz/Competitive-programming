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
    Int n,m,k; cin>>n>>m>>k;
    string op; cin>>op;
    vector<Int> b(m,0); 
    rep(i,m) cin>>b[i];
    vector<Int> a(n,0);
    rep(i,n) cin>>a[i];
    sort(b.begin(),b.end());
    Int ans=0;
    if(op=="+"){
        for(int i=0; i<n; i++){
            Int tmp=k-a[i];
            auto d=lower_bound(b.begin(),b.end(),tmp);
            ans+=(m-distance(b.begin(),d));
        }
    }
    else{
        for(int i=0; i<n; i++){
            Int tmp=0;
            if(k%a[i]==0) tmp=k/a[i];
            else tmp=1+k/a[i];
            auto d=lower_bound(b.begin(),b.end(),tmp);
            ans+=(m-distance(b.begin(),d));
            }
    }
    cout<<ans<<endl;
    return 0;
}