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
    int q; cin>>q;
    for(int i=0; i<q; i++){
        string x,y;
        cin>>x>>y;
        int nx=(int)x.size();
        int ny= (int)y.size();
        vector<vector<Int>> dp(nx+1,vector<Int>(ny+1,0));
        for(int i=0; i<(int)x.size(); i++){
            for(int j=0; j<(int)y.size(); j++){
                if(x[i]==y[j]){
                    dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+1);
                }
                dp[i+1][j+1]=max({dp[i+1][j+1],dp[i][j+1],dp[i+1][j]});
            }
        }
        cout<<dp[nx][ny]<<endl;
    }
    return 0;
}