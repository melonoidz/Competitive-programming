#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
long long x;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(1){
        cin>>x;
        string tmp=to_string(x);
        long long ans=0;
        for(int i=0; i<tmp.length(); i++){
            ans+=(tmp[i]-'0');
        } 
        if (ans==0) break;
        else  {cout<<ans<<endl;}
    }
 
    return 0;
}