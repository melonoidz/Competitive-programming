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
    vector<Int> a(n,0);
    for(Int i=0; i<n; i++) cin>>a[i];
    Int m; cin>>m;
    vector<Int> b(m,0);
    bool flag=true;
    for(Int i=0; i<m; i++) {
        cin>>b[i];
    }
    if(includes(a.begin(),a.end(),b.begin(),b.end())) cout<<1<<endl;
    else cout<<0<<endl;
    return 0;
}