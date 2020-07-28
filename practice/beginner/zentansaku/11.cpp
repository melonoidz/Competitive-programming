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
    vector<vector<pint>> vv;
    for(int i=0; i<n; i++){
        int a; cin>>a;
        vector<pint> voice;
        for(int j=0; j<a; j++){
            int x,y; cin>>x>>y;
            x--;
            voice.emplace_back(pint(x,y));
        }
        vv.emplace_back(voice);
    }
    int ans=0;
    for(int bit=0; bit<(1<<n); bit++){
        bool ok =true;
        for(int i=0; i<n; i++){
            if(bit&(1<<i))
            {
                for(auto w: vv[i])
                {
                    if((w.second==0)&&(bit&(1<<w.first))) ok=false;
                    if((w.second==1)&&!(bit&(1<<w.first))) ok=false;
                }
            }
        }
        if(ok){
            int cnt=0;
            for(int i=0; i<n; i++){
                if(bit&(1<<i)) cnt++;
            }
            ans=max(ans,cnt);
        }
    }
    cout<<ans<<endl;
    return 0;
}