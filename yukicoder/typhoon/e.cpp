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
    vector<int> x(n,0);
    rep(i,n) cin>>x[i];
    Int sum=accumulate(x.begin(),x.end(),0);
    rep(i,n){
        double tmp=n*x[i]/2.0-(double)(sum/2.0);
        tmp/=n;
        cout<<(int)(50+tmp)<<endl;
    }
    return 0;
}