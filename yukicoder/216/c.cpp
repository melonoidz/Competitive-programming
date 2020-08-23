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

bool is_prime(Int a){
    for(Int i=2; i*i<=a; i++){
        if(a%i==0) return false;
    }
    return true;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    Int n; cin>>n;
    Int ans=0;
    for(Int i=2; i<=n; i++){
        if(is_prime(i)){
            if(is_prime(i*i-2)&&(i*i-2<=n)) {
                if(i*i-2==2) ans++;
                else ans+=2;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}