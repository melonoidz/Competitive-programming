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
    int n, q; cin>>n>>q;
    string s; cin>>s;
    int sl=s.size();
    int ans[sl];
    ans[0]=0;
    int cnt=0;
    for(int i=1; i<sl; i++){
        if (s[i-1]=='A'&& s[i]=='C'){
            cnt++;
        }
        ans[i]=cnt;
    }

    for(int i=0; i<q; i++){
        int l,r; cin>>l>>r;
        l--; r--;
        cout<<ans[r]-ans[l]<<endl;
    }
    return 0;
}