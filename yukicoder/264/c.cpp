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

Int digit(Int a){
    string s=to_string(a);
    Int tmp=0;
    for(int i=0; i<(int)s.size(); i++ ){
        tmp+=s[i]-'0';
    }
    return tmp;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n; cin>>n;
    vector<int > a(n,0);
    rep(i,n) cin>>a[i];
    Int count=0;
    bool ok=true;
    for(int i=n-1; i>=0; i--){
        if((a[i]+count)%(i+1)==0){
            count+=(a[i]+count)/(i+1);
        }
        else {
            ok=false;
            break;
        }
    }
    if(ok) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}