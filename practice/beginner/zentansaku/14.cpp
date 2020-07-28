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
    int n,m ; cin>>n>>m;
    int ans=0;
    vector<vector<int>> edge(n,vector<int>());
    for(int i=0; i<m; i++){
        int a,b; cin>>a>>b;
        a--; b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    vector<int> path;
    for(int i=1; i<=n; i++ ) path.emplace_back(i);

    do{
        bool ok=true;
        if (path[0]!=1) ok=false;

        for(int i=0; i<n-1; i++){
            bool c=false;
            for(int j=0; j<edge[path[i]-1].size(); j++){
                if(edge[path[i]-1][j]==path[i+1]-1) c=true;
            }
            if(!c) ok=false; 
        }

        if(ok) ans++;
    }
    while(next_permutation(path.begin(),path.end()));
    cout<<ans<<endl;
    return 0;
}