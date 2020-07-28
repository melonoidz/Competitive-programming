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
    Int n; cin>>n;
    Int ans=LINF;
    Int tmp=0;
    for(Int i=1; i*i<=n; i++){
        if(n%i==0){
            Int a=to_string(i).size();
            Int b=to_string(n/i).size();
            tmp=max(a,b);
            ans=min(ans,tmp);
        }
    }
    cout<<ans<<endl;
    return 0;
}