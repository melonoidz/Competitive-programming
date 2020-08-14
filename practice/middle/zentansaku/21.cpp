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

bool judge(Int a,vector<Int> &h, vector<Int> &s, Int &n){
    vector<Int> ans;
    for(int i=0; i<n; i++){
        if(h[i]>a) return false;
    }
    for(int i=0; i<n; i++){
        Int t=(a-h[i])/s[i];
        ans.emplace_back(t);
    }
    sort(ans.begin(),ans.end());
    for(int i=0; i<n; i++){
        if (i>ans[i]) return false;
    }
    return true;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    Int n; cin>>n;
    vector<Int> h(n);
    vector<Int> s(n);
    rep(i,n){
        cin>>h[i]>>s[i];
    }
    Int ng=-1;
    Int ok=LINF;
    while(abs(ng-ok)>1){
        Int mid=(ng+ok)/2;
        if(judge(mid,h,s,n)){
            ok=mid;
        }
        else ng=mid;
    }
    cout<<ok<<endl;
    return 0;
}
