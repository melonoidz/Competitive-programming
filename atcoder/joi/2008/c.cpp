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
    Int n,m; cin>>n>>m;
    vector<Int> p(n);
    rep(i,n) cin>>p[i];
    p.emplace_back(0);
    sort(p.begin(),p.end());
    Int ans=0;
    set<Int> tmp;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            Int g=p[i]+p[j];
            tmp.insert(g);
        }
    }
vector<Int> half(tmp.begin(),tmp.end());
sort(half.begin(),half.end());

for(int i=0; i<(int)half.size(); i++){
    if(half[i]<=m){
    auto y=upper_bound(half.begin(),half.end(),m-half[i])-half.begin()-1;
    Int cnt=half[i]+half[y];
    ans=max(ans,cnt);
    }
}
cout<<ans<<endl;
return 0;
}