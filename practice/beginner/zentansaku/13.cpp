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
    vector<int> p(n,0);
    vector<int> q(n,0);
    rep(i,n) cin>>p[i];
    rep(i,n) cin>>q[i];
    int a=0;
    int b=0;
    vector<int> count;
    rep(i,n) count.emplace_back(i+1);
    int cnt=0;
    do{
        bool ap=true;
        bool bq=true;
        for(int i=0; i<n; i++){
            if(count[i]!=p[i]) ap=false;
            if(count[i]!=q[i]) bq=false;
        }
        cnt++;
        if(ap) a=cnt;
        if(bq) b=cnt; 
    }
    while(next_permutation(count.begin(),count.end()));
    cout<<abs(a-b)<<endl;
    return 0;
}