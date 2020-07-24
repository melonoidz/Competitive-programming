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
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin>>n;
    vector<vector<vector<int>>> building;
    building.resize(4);
    for(size_t i=0; i<4; i++){
        building[i].resize(3);
        for(size_t j=0; j<3; j++){
            building[i][j].resize(10);
        }
    }
    for(int i=0; i<n; i++){
        int b,f,r,v;
        cin>>b>>f>>r>>v;
        building[b-1][f-1][r-1]+=v;
    }
    for(int i=0; i<4; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<10; k++){
                cout<<" "<<building[i][j][k];
            }
            cout<<endl;
        }
        if(i<3) cout<<"####################"<<endl;
        if(i==4) cout<<endl;
    }
    return 0;
}