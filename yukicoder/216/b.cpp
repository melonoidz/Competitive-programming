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
    int a,b,c,d,e,f,g;
    cin>>a>>b>>c>>d>>e>>f>>g;
    int aa,bb,cc,dd,ee,ff;
    aa=g/500;
    g-=500*aa;
    bb=g/100;
    g-=100*bb;
    cc=g/50;
    g-=50*cc;
    dd=g/10;
    g-=10*dd;
    ee=g/5;
    g-=5*ee;
    ff=g/1;
    g-=1*ff;
    if((g==0)&&(aa<=a)&&(bb<=b)&&(cc<=c)&&(dd<=d)&&(ee<=e)&&(ff<=f)){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}