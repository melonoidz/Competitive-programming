#include <bits/stdc++.h>

using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    vector<int> p;
    for (int i=0; i<n; i++){
        int v; cin>>v;
        p.push_back(v);
    }
    std::sort(p.begin(),p.end());
    int ans=0;
    for(int i=0; i<k; i++){
        ans+=p[i];
    }
    cout<<ans<<endl;
    return 0;
}