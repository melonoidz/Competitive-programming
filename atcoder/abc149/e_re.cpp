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
int n, m;
vc<int> a;

bool che(int x) {
    int tmp = 0;
    for (int i = 0; i < n; i++) {
        auto d = lower_bound(a.begin(), a.end(), x - a[i]) - a.begin();
        tmp += (n - d);
    }
    return tmp < m;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> n >> m;
    a.resize(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    int ng = 0;
    int ok = 2e9;
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (che(mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    vc<int> su(n + 1, 0);
    for (int i = 0; i < n; i++) {
        su[i + 1] = su[i] + a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto d = lower_bound(a.begin(), a.end(), ok - a[i]) - a.begin();
        int cnt = n - d;
        ans += a[i] * cnt + (su[n] - su[d]);
        m -= cnt;
    }
    if (m > 0) {
        ans += (ok - 1) * m;
    }
    cout << ans << endl;
}