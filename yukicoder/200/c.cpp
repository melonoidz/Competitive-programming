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
    Int a; cin>>a;
    vector<Int> cnt;
    cnt.emplace_back(a);
    for(int i=1; i<n; i++){
        Int v; cin>>v;
        cnt.emplace_back(v);
        a=__gcd(a,v);
    }
    for(int i=0; i<n-1; i++){
        cout<<cnt[i]/a<<":";
    }
    cout<<cnt[n-1]/a<<endl;
    return 0;
}