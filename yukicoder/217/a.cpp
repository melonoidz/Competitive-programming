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

Int judge(Int n, Int s){
    if(n%s==0) return n/s;
    else return n/s+1;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    Int p,q,r; cin>>p>>q>>r;
    Int a,b,c; cin>>a>>b>>c;
    Int t= __gcd(a,b);
    Int g= __gcd(t,c);
    Int j= a*b*c/g;
    Int ans_min=LINF;
    Int ans_max=0;
    Int cnt=0;
    for(Int i=1; i<=j; i++){
        Int x,y,z;
        x=judge(i,p);
        y=judge(i,q)-x;
        z=judge(i,r)-x-y;
        if((x==a)&&(y==b)&&(z==c)) {
            ans_min=min(ans_min,i);
            ans_max=max(ans_max,i);
            cnt++;
        }
    }
    if(cnt==0) cout<<-1<<endl;
    else cout<<ans_min<<" "<<ans_max<<endl;
    return 0;
}