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
    int n; cin>>n;
    set<Int> s;
    rep(i,n) {
        Int a; cin>>a; 
        s.insert(a);
        }
    int q; cin>>q;
    vector<Int> t(q,0);
    rep(i,q) cin>>t[i];
    int ans=0;
    for(int i=0; i<q; i++){
        for(auto x: s){
            if(t[i]==x) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}