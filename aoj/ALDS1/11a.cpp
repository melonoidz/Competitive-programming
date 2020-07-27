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
    vector<vector<int>> edge(110);
    int n; cin>>n;
    for(int i=0; i<n; i++)
    {
        int u; cin>>u;
        u--;
        int k; cin>>k;
        if(k!=0) {
        for(int j=0; j<k; j++){
            int v; cin>>v;
            v--;
            edge[u].push_back(v);
        }
    }
    }
    for(int i=0; i<n; i++){
        vector<int> ans(n,0);
        for(int j=0; j<edge[i].size(); j++){
            ans[edge[i][j]]++;
        }
        for(int k=0; k<n; k++){
            cout<<ans[k]<<(k==n-1?'\n':' ');
        }
    }
    return 0;
}