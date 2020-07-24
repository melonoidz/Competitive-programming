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
    int n,k; cin>>n>>k;
    vector<int> a(n,0);
    rep(i,n) cin>>a[i];
    int q; cin>>q;
    vector<Int> sum_a(n+1,0);
    sum_a[0]=0;
    for(int i=0; i<n; i++){
        sum_a[i+1]=sum_a[i]+a[i];
    }
    vector<Int> S;
    for(int i=1; i<=n-k+1; i++){
        Int tmp=sum_a[i+k-1]-sum_a[i-1];
        S.emplace_back(tmp);
    }
    sort(S.begin(),S.end());    
    rep(i,q){
        Int x; cin>>x;
        auto d= upper_bound(S.begin(),S.end(),x);
        cout<<distance(S.begin(),d)<<endl;
    }
    return 0;
}