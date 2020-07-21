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
    vector<Int> ans;
    int q; cin>>q;
    for(int i=0; i<q; i++){
        string a,b; cin>>a;
        if(a=="0"){
            cin>>b;
            Int x=stoll(b);
            ans.emplace_back(x);
        } 
        else if(a=="1"){
            cin>>b;
            Int p =stoll(b);
            cout<<ans[p]<<endl;
        }
        else{
            ans.pop_back();
        }
    }
    return 0;
}