#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k; cin>>n>>k;
    int h[100100];

    for(int i=0; i<n; i++) cin>>h[i];
    vector<long long> cost(n,0);
    cost[0]=0;

    for(int i=1; i<n; i++){
        long long tmp=INF;
        for(int j=1; j<=k; j++){
            if (i-j>=0) tmp=min(tmp,cost[i-j]+abs(h[i]-h[i-j]));
            else continue;
        }
        cost[i]=tmp;
    }
    cout<<cost[n-1]<<endl;
    return 0;
}