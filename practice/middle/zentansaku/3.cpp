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

Int dist(pint a, pint b){
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}

pint kat(pint a, pint b){
    int xx=b.first-a.first;
    int yy=b.second-a.second;
    return pint(xx,yy);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin>>n;
    vector<pint> u;
    for(int i=0; i<n; i++){
        int x,y; cin>>x>>y;
        u.emplace_back(pint(x,y));
    }
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            
        }
    }


    return 0;
}