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

Int div(int a){
    Int ans=0;
    for(int i=1; i*i<=a; i++){
        if(a%i==0) ans+=2;
        if(i*i==a) ans--;
    }
    return ans;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin>>n;
    int tmp=0;
    for(int i=1; i<=n; i=i+2){
        if(div(i)==8) tmp++;
    }
    cout<<tmp<<endl;
    return 0;
}