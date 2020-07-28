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
    int N,M; cin>>N>>M;
    int ans=0;
    vector<vector<int>> s(M);
    for(int i=0; i<M; i++){
        int k; cin>>k;
        for(int j=0; j<k; j++){
            int a; cin>>a;
            a--;
            s[i].emplace_back(a);
        }
    }

    vector<int> p(M);
    for(int i=0; i<M; i++) cin>>p[i];

    for(int bit=0; bit<(1<<N); bit++){
        bool ok=true;
        for(int i=0; i<M; i++){
            int cnt=0;
            for(auto v: s[i]){
                if(bit&(1<<v)) cnt++;
            }
            if(cnt%2!=p[i]) ok =false;
        }
        if(ok) ans++;
    }
    cout<<ans<<endl;

    return 0;
}