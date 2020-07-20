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
    int n;  cin>>n;
    vector<long long> a(0);
    REP(i,n){long long v; cin>>v;
    a.emplace_back(v);
    }
    sort(a.begin(),a.end());
    long long ans=0;
    for(int i=1; i<n; i++){
        ans+=a[i];
    }
 
    cout<<ans<<endl;
    return 0;
}