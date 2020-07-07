#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string a,b;
    cin>>a>>b;
    string convb="";
    for(int i=0; i<b.length(); i++){
        if(b[i]!='.'){
            convb+=b[i];
        }
    }
    long long conva= stoll(a);
    long long newb=stoll(convb);
    cout<<conva*newb/100<<endl;
    return 0;
}