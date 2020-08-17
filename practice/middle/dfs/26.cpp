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

void dfs(vector<vector<int>> &tree, vector<bool> &seen, int k, vector<int> &ans, vector<int> &point){
    seen[k]=true;
    for(int i: tree[k]){
        if(seen[i]) continue;
        else{
            ans[i]=ans[k]+point[i];
            dfs(tree,seen,i,ans,point);
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,q; cin>>n>>q;
    vector <vector<int>> tree(n);
    vector<int> point(n,0);
    vector<bool> seen(n,false);
    for(int i=0; i<n-1; i++){
        int a,b; cin>>a>>b;
        a--; b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    rep(i,q){
        int p,x;
        cin>>p>>x;
        p--;
        point[p]+=x;
    }
    vector<int> ans(n,0);
    ans[0]=point[0];
    dfs(tree,seen,0,ans,point);
    rep(i,n) cout<<ans[i]<<" ";
    return 0;
}