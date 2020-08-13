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

Int judge(string a, string b){
    int al=(int)a.size();
    int bl=(int)b.size();
    vector<vector<int>> dp(al+1,vector<int>(bl+1,0));
    //if(a[0]==b[0]) dp[0][0]=1;
    for(int i=0; i<al; i++){
        for(int j=0; j<bl; j++){
          if(a[i]==b[j]){
              dp[i+1][j+1]=max(dp[i][j]+1, dp[i+1][j+1]);
          }  
        dp[i+1][j+1]=max({dp[i+1][j+1],dp[i+1][j],dp[i][j+1]});
        }
    }
    return dp[al][bl];
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int q; cin>>q;
    for(int i=0; i<q; i++){
        string a,b; cin>>a>>b;
        cout<<judge(a,b)<<endl;
    }
    return 0;
}