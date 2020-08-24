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
    Int l,r; cin>>l>>r;
    int n; cin>>n;
    int fi=l%n;
    int cir=n-fi;
    int af=(r-l+1)%cir;
    for(int i=1; i<=n; i++){
        int ans=0;
        ans=(r-l+1)/cir;
        if(((r-l+1)%cir+fi)%n>=i) ans++;
        cout<<ans<<endl;
    }


    return 0;
}