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
    long long n,d;
    cin>>n>>d;
    vector<long long>a(0);
    for(int i=0; i<n; i++){
        long long aa; cin>>aa;
        a.emplace_back(aa);
    }
    vector<long long>b(0);
    for(int i=0; i<n; i++){
        b.emplace_back((d+a[i])*(-1));
    }
    sort(b.begin(), b.end());
    for(int i=0; i<n; i++){
        long long cnt= a[i]*(-1);
        auto ans=lower_bound(b.begin(), b.end(), cnt);
        cout<<n-distance(b.begin(),ans)<<endl;
    }

    return 0;
}