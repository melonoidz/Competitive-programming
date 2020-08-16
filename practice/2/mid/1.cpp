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
    int n,x;
    while(true){
        cin>>n>>x;
        if(n==0 && x==0 )break;
        int ans=0;
        for(int i=1; i<=n-2; i++){
            for(int j=i+1; j<=n-1; j++ ){
                for(int k=j+1; k<=n; k++){
                    if(i+j+k==x) ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}