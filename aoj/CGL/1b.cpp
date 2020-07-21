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
int xp1,yp1,xp2,yp2;
int q;


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>xp1>>yp1>>xp2>>yp2;
    cin>>q;
    auto va = P(xp2-xp1,yp2-yp1);
    for(int i=0; i<q; i++){
        int x,y; cin>>x>>y;
        auto vb=P(x-xp1,y-yp1);
        Int vab=va.first*vb.first+va.second*vb.second;
        Int vaa=va.first*va.first+va.second*va.second;
        pair<double,double> oh;
        oh.first=(double)va.first*vab/vaa;
        oh.second=(double)va.second*vab/vaa;
        double xans=oh.first+xp1/1.000000000;
        double yans=oh.second+yp1/1.000000000;
        cout<<fixed<<setprecision(10)<<(double)(xans*2.0-x/1.0)<<" "<<fixed<<setprecision(10)<<(double)(yans*2.0-y/1.0)<<endl;
    }


    return 0;
}