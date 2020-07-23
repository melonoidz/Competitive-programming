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
    int n,m ; cin>>n>>m;
    vector<int> c(m,0);
    rep(i,m) cin>>c[i];
    sort(c.begin(),c.end(),greater<int>());
    
    vector<int> coin(50100,INF);
    rep(i,m) coin[c[i]]=1;
    for(int i=1 ; i<=n; i++){
        for(int j=0; j<m; j++){
            if(i-c[j]>=0){
            coin[i]=min(coin[i],coin[i-c[j]]+1);}
        }
    }
    cout<<coin[n]<<endl;
    
    return 0;
}