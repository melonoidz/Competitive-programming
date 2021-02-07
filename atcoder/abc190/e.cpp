#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
#define int ll
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
template <class t, class u> void chmax(t& a, u b) {
    if (a < b) a = b;
}
template <class t, class u> void chmin(t& a, u b) {
    if (b < a) a = b;
}
template <class t> using vc = vector<t>;
template <class t> using vvc = vc<vc<t>>;
using pi = pair<int, int>;
using vi = vc<int>;
using uint = unsigned;
using ull = unsigned long long;
int popcount(signed t) { return __builtin_popcount(t); }
int popcount(ll t) { return __builtin_popcountll(t); }
bool ispow2(int i) { return i && (i & -i) == i; }
ll mask(int i) { return (ll(1) << i) - 1; }
int lcm(int a, int b) { return a / __gcd(a, b) * b; }
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    // edge, vertex(=stone)
    // bitDP?
    vc<vc<int>> G;
    int n, m;
    cin >> n >> m;
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int k;
    cin >> k;
    vc<int> c(k, 0);
    rep(i, k) cin >> c[i];
    vc<vc<int>> dp(1 << k, vc<int>(20, 1e9));
    dp[0][0] = 1e9;
    for(int bit=0; bit<1<<k; bit++){
      for(int i=0; i<k; i++){
        for(int j=0; j<k; j++){
            if(i!=j) {
              if(){
                dp[bit|(1<<i)][j]=min(dp[bit|(1<<i)][j])
              }
            }
        }
      }
    }
    return 0;
}