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

void solve(vector<int> a){
    for(int i=0; i<a.size(); i++){
        if(i<a.size()-1) cout<<a[i]<<" ";
        else cout<<a[i]<<endl;
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin>>n;
    vector<int> a(n,0);
    rep(i,n) cin>>a[i];
    
    return 0;
}