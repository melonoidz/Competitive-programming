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
    int n; cin>>n;
    int h[100100];
    for (int i=0; i<n; i++){
        cin>>h[i];
    }
    long long cost[100100];
    cost[0]=0;
    cost[1]=abs(h[1]-h[0]);
    if (n==2) cout<<cost[1]<<endl;
    else{
    for(int i=0; i<n-2; i++){
        cost[i+2]=min(cost[i+1]+abs(h[i+2]-h[i+1]),cost[i]+abs(h[i+2]-h[i]));
    }
    cout<<cost[n-1]<<endl;
    }
    return 0;
}