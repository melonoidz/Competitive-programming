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
    int n,w; cin>>n>>w;
    vector<Int> ans(w+1,0);
    vector<int> we(n,0);
    vector<int> va(n,0);
    rep(i,n) cin>>we[i]>>va[i];
    for(int i=1; i<=w; i++){
        for(int j=0; j<n; j++){
            if(i-we[j]>=0) ans[i]=max(ans[i],ans[i-we[j]]+va[j]);
        }
    }
    cout<<ans[w]<<endl;
    return 0;
}