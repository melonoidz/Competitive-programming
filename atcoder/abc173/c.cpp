#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();

int h,w,k;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>h>>w>>k;
    char field[h][w];
    for(int i=0; i<h; i++){
        for (int j=0; j<w; j++){
            char a; cin>>a;
            field[i][j] = a;
        }
    }
    int ans=0; 
    for(int i=0; i<(1<<h); i++){
        for(int j=0; j<(1<<w); j++){
            
        }
    }
    
    
    return 0;
}