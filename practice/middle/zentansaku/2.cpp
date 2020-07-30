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
    int n,m; cin>>n>>m;
    vector<vector<Int>> a;
    for(int i=0; i<n; i++){
        vector<Int> tmp;
        for(int j=0; j<m; j++){
            Int v; cin>>v;
            tmp.emplace_back(v);
        }
        a.emplace_back(tmp);
    }
    Int ans=0;
    for(int i=0; i<m-1; i++){
        for(int j=i+1; j<m; j++){
            Int point=0;
            for(int k=0; k<n; k++){
                point+=max(a[k][i],a[k][j]);
            }
            ans=max(ans,point);
        }
    }
    cout<<ans<<endl;
    return 0;
}