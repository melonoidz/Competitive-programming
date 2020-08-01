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
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin>>n;
    vector<int> a(n,0);
    rep(i,n) cin>>a[i];
    int q; cin>>q;
    vector<int> m(q,0);
    rep(i, q)  {
        cin>>m[i];
    }
    vector<Int> Ans;
    for(int bit=0; bit<(1<<n); bit++){
        Int ans=0;
        for(int i=0; i<n; i++){
            if(bit&(1<<i)) ans+=a[i];
        }
        Ans.emplace_back(ans);
    }
    sort(Ans.begin(),Ans.end());
    for(int i=0; i<q; i++){
        if(binary_search(Ans.begin(),Ans.end(),m[i])){
            cout<<"yes"<<endl;
        }else{
            cout<<"no"<<endl;
        }
    }

    return 0;
}