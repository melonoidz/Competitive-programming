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
    string s; cin>>s;
    int ans=0;
    for(int i=0; i<(int)s.size(); i++){
        if(s[i]=='A'||s[i]=='C'||s[i]=='G'||s[i]=='T'){
            int cnt=0;
            while(s[i+cnt]=='A'||s[i+cnt]=='C'||s[i+cnt]=='G'||s[i+cnt]=='T'){
                cnt++;
            }
            ans=max(ans,cnt);
        }
    }
    cout<<ans<<endl;
    return 0;
}