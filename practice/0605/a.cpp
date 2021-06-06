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
    int n, m;
    cin >> n >> m;
    vc<int> x(n);
    int ans = 0;
    map<int, int> t1, t2;
    rep(i, n) {
        cin >> x[i];
        t1[x[i]]++;
    }
    for (auto u : t1) {
        int cnt = u.second;
        ans += cnt / 2;
        t2[u.first % m] += cnt % 2;
    }
    for (auto u : t2) {
        int f = u.first;
        if (f == 0 || 2 * f == m) {
            ans += u.second / 2;
        } else {
            int pr = t2[(m - f) % m];
            int add = min(u.second, pr);
            ans += add;
            u.second -= add;
            t2[(m - f) % m] -= add;
        }
    }
    cout << ans << endl;
}