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
    int n; cin>>n;
    vector<vector<int>> ans(n,vector<int>(n,0));
    for(int i=1; i<=n; i++){
        ans[i-1][i-1]=i;
        if(i>1){
        for(int j=i-2; j>=0; j--){
            if(abs(j-(i-1))+i<=n) ans[i-1][j]=abs(j-(i-1))+i;
            else ans[i-1][j]=abs(j-(i-1))+i-n;
        }
        }
        for(int j=i; j<=n; j++){
            if(i-abs(j-(i-1))>=1) ans[i-1][j]=i-abs(j-(i-1));
            else ans[i-1][j]=i-abs(j-(i-1))+n;
        }
    } 
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<ans[i][n-1]<<endl;
    }
    return 0;
}