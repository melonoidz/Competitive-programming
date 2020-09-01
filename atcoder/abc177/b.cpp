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
    string t; cin>>t;
    Int ans=LINF;
    for(int i=0; i<=(int)s.size()-(int)t.size(); i++){
      Int tmp=0;
      for(int j=0; j<(int)t.size(); j++){
        if(s[i+j]!=t[j]) tmp++;
      }
      ans=min(ans,tmp);
    }
    cout<<ans<<endl;
    return 0;
}