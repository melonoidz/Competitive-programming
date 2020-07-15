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
    int n; cin>>n;
    vector<int> a(n,0); 
    vector<int> b(n,0); 
    vector<int> c(n,0); 
    rep(i,n) cin>>a[i]>>b[i]>>c[i];
    vector<vector<long long>> cost(3,vector<long long>(n,0));

    cost[0][0]=a[0];
    cost[1][0]=b[0];
    cost[2][0]=c[0];

    for(int i=0; i<n-1; i++){
        cost[0][i+1]=max(cost[1][i]+a[i+1],cost[2][i]+a[i+1]);
        cost[1][i+1]=max(cost[0][i]+b[i+1],cost[2][i]+b[i+1]);
        cost[2][i+1]=max(cost[0][i]+c[i+1],cost[1][i]+c[i+1]);
    }
    cout<<max({cost[0][n-1],cost[1][n-1],cost[2][n-1]})<<endl;
    return 0;
}