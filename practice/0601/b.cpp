#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
#define int ll
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define ALL(a) (a).begin(), (a).end()
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
    // 1操作でn-1減る k回ならk(n-1)
    // n=2 k=0 ->{1,1} k=1 {2,0} k=2  N=3{4,0}
    // 均等に処理すると-1ずつ減る
    // n=50
    int k;
    cin >> k;
    const int n = 50;
    vc<int> ans;
    cout << n << endl;
    int cnt = k % 50;
    rep(i, cnt) ans.push_back(50);
    rep(i, n - cnt) ans.push_back(49 - cnt);
    int r = k / 50;
    rep(i, 50) cout << ans[i] + r << " ";
    cout << endl;
}