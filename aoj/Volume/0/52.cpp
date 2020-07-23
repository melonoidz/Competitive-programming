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
    int n;
    while (cin>>n)
    {
        if(n==0) break;
        Int ans=0;
        ans+=(n/pow(5,1));
        ans+=(n/pow(5,2));
        ans+=(n/pow(5,3));
        ans+=(n/pow(5,4));
        ans+=(n/pow(5,5));
        ans+=(n/pow(5,6));
        cout<<ans<<endl;
    }
    
    return 0;
}