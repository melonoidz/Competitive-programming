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
    int n; cin>>n;
    vector<int> a(n,0);
    rep(i,n) cin>>a[i];
    int cnt=0;
    bool flag=true;
    while (flag)
    {
        flag=false;
        for(int j=0; j<n-1; j++){
            if(a[j]<a[j+1]) {
                swap(a[j],a[j+1]);
                flag=true;
                cnt++;
            }
        }
    }
    for(int i=1; i<=n; i++) cout<<i<<(i==n?'\n':' ');
    cout<<cnt<<endl;
    return 0;
}