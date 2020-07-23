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
    int N,W; cin>>N>>W;
    vector<int> value(110,0);
    vector<int> weight(110,0);
    vector<vector<Int>> cost(110,vector<Int>(100100,0));
    for(int i=1; i<=N; i++) cin>>value[i]>>weight[i];
    cost[0][0]=0;
    for(int i=1; i<=N; i++){
        for(int j=0; j<=W; j++){
        if (j-weight[i]>=0) cost[i][j]=max(cost[i-1][j],cost[i-1][j-weight[i]]+value[i]);
        cost[i][j]=max(cost[i][j],cost[i-1][j]);
        }
    }
    Int ans=0;
    for(int i=0; i<=N; i++){
        for(int j=0; j<=W; j++){
        ans=max(ans,cost[i][j]);
    }
    }
    cout<<ans<<endl;
    return 0;
}