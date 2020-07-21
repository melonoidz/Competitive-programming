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
int v,e,r;
vector<P> edge[2200];

vector<Int> bellmanFord(int start){
    vector<Int> dist(v,LINF);
    
}


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>v>>e>>r;
    for(int i=0; i<e; i++){
        int s,t,d; cin>>s>>t>>d;
        edge[s].emplace_back(P(t,d));
    }
    auto dist= bellmanFord(r);
    for (int i = 0; i < v; i++)
    {
        if (dist[i] == LINF)
            cout << "INF" << endl;
        else
            cout << dist[i] << endl;
    }
    return 0;
}