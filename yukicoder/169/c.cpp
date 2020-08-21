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
    Int n; cin>>n;
    string a=to_string(n);
    string ans;
    bool flag=true;
    if (n<0) flag=false;
    for(int i=0; i<(int)a.size(); i++){
        if(a[i]=='7') ans+='6';
        else ans+=a[i];
    }
    Int tmp=stoll(ans);
    if(!flag) tmp*(-1);
    Int anstmp=n-tmp;
    cout<<tmp<<" "<<anstmp<<endl;
    return 0;
}