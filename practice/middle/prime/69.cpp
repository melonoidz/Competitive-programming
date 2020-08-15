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

bool is_prime(Int N) {
    if (N == 1) return false;
    for (Int i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}

bool judge(Int a){
    if(is_prime(a) && is_prime((a+1)/2)) return true;
    return false;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int q; cin>>q;
    vector<int> ans(100010,0);
    int tmp=0;
    for(int i=1; i<=100000; i++){
        if(judge(i)){
            tmp++;
            ans[i]=tmp;
        }
        else ans[i]=tmp;
    }
    for(int i=0; i<q; i++){
        int l,r; cin>>l>>r;
        cout<<ans[r+1]-ans[l-1]<<endl;
    }
    return 0;
}