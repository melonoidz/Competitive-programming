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
    int a,b,k; cin>>a>>b>>k;
    int tmp=__gcd(a,b);
    vector<int> ans;
    for(int i=1; i*i<=tmp; i++){
        if(tmp%i==0){
            ans.emplace_back(i);
            if(i*i!=tmp){
                ans.emplace_back(tmp/i);
            }
        }
    }
    sort(ans.begin(),ans.end());
    reverse(ans.begin(),ans.end());
    cout<<ans[k-1]<<endl;
    return 0;
}