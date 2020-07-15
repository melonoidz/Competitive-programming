#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,W; cin>>N>>W;
    int w[110];
    long long v[110];
    for(int i=1; i<=N; i++) cin>>w[i]>>v[i];
    vector<vector<long long>>cost(110,vector<long long>(W+1,0));

    for(int i=1; i<=N; i++){
        for(int j=0; j<=W; j++){
            if (j-w[i]>=0) cost[i][j]=max(cost[i-1][j],cost[i-1][j-w[i]]+v[i]);
            cost[i][j]=max(cost[i][j],cost[i-1][j]);
        }
    }
    long long ans=0;
    for(int j=0; j<=W; j++) ans=max(ans,cost[N][j]);
    cout<<ans<<endl;
    return 0;
}