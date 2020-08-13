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
// https://www.ioi-jp.org/joi/2010/2011-yo-prob_and_sol/2011-yo-t4/review/2011-yo-t4-review.html

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin>>n;
    vector<Int> a(n,0);
    rep(i,n) cin>>a[i];
    vector<vector<Int>> dp(n+1,vector<Int>(21,0));
    for(int i=0; i<n-1; i++){
        for(int j=0; j<=20; j++){
            if(j-a[i]>=0){
                dp[i][j-a[i]]++;
            }
            if(j+a[i]<=20){
                dp[i][j+a[i]]++;
            }
        }
    }
    cout<<dp[n-2][a[n-1]]<<endl;
    return 0;
}