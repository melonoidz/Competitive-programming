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
    vector<int> cnt(110,0);
    vector<int> ans;
    int n; 
    while(cin>>n){
        cnt[n]++;
    }
    int y=0;
    for(int i=1; i<=100; i++){
        y=max(y,cnt[i]); 
    }
    for(int i=1; i<=100; i++){
        if(cnt[i]==y) ans.emplace_back(i);
    }
    for(auto& a: ans){
        cout<<a<<endl;
    }

    return 0;
}