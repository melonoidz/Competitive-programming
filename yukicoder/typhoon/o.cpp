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
typedef pair<int, int> pint;
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin>>n;
    vector<int> cnt(400010,0);
    int sub=200000;
    rep(i,n){
        int x,r;
        cin>>x>>r;
        x+=sub;
        cnt[x-r]++;
        cnt[x+r]--;
    }
    vector<int> ans(400010,0);
    ans[0]=cnt[0];
    for(int i=0; i<400010-1; i++){
        ans[i+1]=ans[i]+cnt[i];
    }
    int pn=0;
    for(int i=0; i<(int)ans.size(); i++){
        pn=max(pn,ans[i]);
    }
    cout<<pn<<endl;

    return 0;
}