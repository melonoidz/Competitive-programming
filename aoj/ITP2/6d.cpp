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
    vector<Int> a(n,0);
    rep(i,n) cin>>a[i];
    int q; cin>>q;
    for(int i=0; i<q; i++){
        Int k ; cin>>k;
        auto dl=lower_bound(a.begin(),a.end(),k);
        auto ul = upper_bound(a.begin(),a.end(),k);
        cout<<distance(a.begin(),dl)<<" "<<distance(a.begin(),ul)<<endl;
            }
    return 0;
}