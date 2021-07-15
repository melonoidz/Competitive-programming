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
    int n;
    cin >> n;
    vc<double> t(n), v(n);
    rep(i, n) cin >> t[i];
    rep(i, n) cin >> v[i];
    int total = accumulate(ALL(t), 0LL);
    vc<double> V(2 * total + 1, double(1e9));
    int now = 0;
    rep(i, n) {
        rep(ti, t[i]) {
            int t1 = now + ti * 2;
            int t2 = t1 + 1;
            V[t1] = min(V[t1], v[i]);
            V[t2] = min(V[t2], v[i]);
        }
        now += t[i] * 2;
        V[now] = min(V[now], v[i]);
    }
    V[0] = 0.0, V[total * 2] = 0.0;
    rep(i, total * 2 + 1) { V[i + 1] = min(V[i + 1], V[i] + 0.5); }
    for (int i = total * 2 + 1; i > 0; i--) {
        V[i - 1] = min(V[i] + 0.5, V[i - 1]);
    }
    // calc
    double ans = 0.0;
    rep(i, 2 * total + 1) { ans += (V[i] + V[i + 1]) * 0.5; }
    cout << ans / 2.0 << endl;
}