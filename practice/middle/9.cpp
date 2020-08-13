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
    int m; cin>>m;
    int n;
    vector<Int> sign_x;
    vector<Int> sign_y;
    vector<Int> star_x;
    vector<Int> star_y;
    rep(i,m) {
        Int a,b; cin>>a>>b;
        sign_x.push_back(a);
        sign_y.push_back(b);
    }
    cin>>n;
    rep(i,n){
        Int a,b; cin>>a>>b;
        star_x.push_back(a);
        star_y.push_back(b);
    }
    vector<Int> jx(star_x.size());
    copy(star_x.begin(),star_x.end(),jx.begin());
    vector<Int> jy(star_y.size());
    copy(star_y.begin(),star_y.end(),jy.begin());
    sort(jx.begin(),jx.end());
    sort(jy.begin(),jy.end());
    for(int i=0; i<n; i++){
        Int fa=star_x[i]-sign_x[0];
        Int fb=star_y[i]-sign_y[0];
        bool flag=true;
        for(int j=1; j<m; j++){
            Int jjx=sign_x[j]+fa;
            Int jjy=sign_y[j]+fb;
            if(!(binary_search(jx.begin(),jx.end(),jjx))||!(binary_search(jy.begin(),jy.end(),jjy))){
                flag=false;
            }
            if(!flag) break;
        }
        if(flag){
            cout<<fa<<" "<<fb<<endl;
            return 0;
        }
    }
    return 0;
}