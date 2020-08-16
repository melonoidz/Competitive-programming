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
int dx[]={-1,0,1,-1,1,-1,0,1};
int dy[]={-1,-1,-1,0,0,1,1,1};
int ans;
int w,h; 
int c[55][55];
int v[55][55];
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);  
    while(true){
        cin>>w>>h;
        if(w==0 && h==0) break;
        rep(i,h){
            rep(j,w) {cin>>c[i][j]; v[i][j]=0;}
        }
        ans=0;
        rep(i,h){
            rep(j,w){
                if(c[i][j]==1 && v[i][j]==0){
                    ans++;                  
                    queue<pint> q;
                    q.push(pint(i,j));
                    while(!q.empty()){
                        pint p=q.front(); q.pop();
                        int x=p.second;
                        int y=p.first;
                        v[y][x]=1;
                        for(int k=0; k<8; k++){
                            int nx=x+dx[k];
                            int ny=y+dy[k];
                            if(nx<0||ny<0||w<=nx||h<=ny) continue;
                            else{
                            if(c[ny][nx]==1 && v[ny][nx]==0){
                                q.push(pint(ny,nx));
                            }
                            else continue;
                            }
                        }
                    }
                }
                else continue;
            }
        }
        cout<<ans<<endl;
    }
    
   return 0;
}