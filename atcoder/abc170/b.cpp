#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();

int x;
int y;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
     cin>>x>>y;
     for(int i=0; i<=x; i++){
         int cnt=i*2+(x-i)*4;
         if(cnt==y){
             cout<<"Yes"<<endl;
             return 0;
         }
     }
     cout<<"No"<<endl;          
    return 0;
}