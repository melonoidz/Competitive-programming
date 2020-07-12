#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();

int h,w,k;
string s[6];
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>h>>w>>k;
    for(int i=0; i<h; i++){
        cin>>s[i];
    }
    int ans=0;
    for(int i=0; i<(1<<h); i++){
        for(int j=0; j<(1<<w); j++){
            int cnt=0;
            for(int I=0; I<h; I++){
                for(int J=0; J<w; J++){
                    if(!(i&(1<<I))&&!(j&(1<<J))){
                        if(s[I][J]=='#'){
                            cnt++;
                        };
                    }
                }
            }
            if(cnt==k) ans++;
        }
    }
    cout<<ans<<endl;    
    return 0;
}