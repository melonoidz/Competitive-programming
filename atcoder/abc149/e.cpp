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
int n, m, ans;
vc<int> a;
bool check(int x) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int pos = lower_bound(a.begin(), a.end(), x - a[i]) - a.begin();
        cnt += (n - pos);
    }
    return cnt < m;
    //たしかに
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> n >> m;
    a.resize(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    //二分探索
    int ng = 0;
    int ok = 2e9;
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (check(mid)) {
            ok = mid;
            // midがm未満に入れるならもっと下げる
        } else {
            ng = mid;
        }
    }
    vc<int> wa(n + 1);
    for (int i = 0; i < n; i++) {
        wa[i + 1] = wa[i] + a[i];
    }
    for (int i = 0; i < n; i++) {
        int pos = lower_bound(a.begin(), a.end(), ok - a[i]) - a.begin();
        int cnt = n - pos;
        ans += cnt * a[i] + (wa[n] - wa[pos]);  //(a[pos]+...+a[n-1]) :n-pos個
        m -= cnt;
    }
    // lower_boundは未満の左端を返す
    // upper_boundはより大きいの左端を返す
    //<=を調べたい場合は-1のupper_bound
    ans += m * ng;
    cout << ans << endl;
}