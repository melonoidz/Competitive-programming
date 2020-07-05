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
    int n;
    cin>>n;
    int ans[]={0,0,0,0};
    for (int i=0; i<n; i++){
        string s;
        cin>>s;
        if (s=="AC"){
            ans[0]++;
        }
        else if(s=="WA"){
            ans[1]++;
        }
        else if (s=="TLE"){
            ans[2]++;
        }
        else{
            ans[3]++;
        }
    } 
    cout<<"AC x "<<ans[0]<<"\n";
    cout<<"WA x "<<ans[1]<<"\n";
    cout<<"TLE x "<<ans[2]<<"\n";
    cout<<"RE x "<<ans[3]<<"\n";

    return 0;
}