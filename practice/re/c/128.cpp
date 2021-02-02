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
    int n, m;
    cin >> n >> m;
    int ans = 0;
    vc<vc<int>> SW(n);
    rep(i, m) {
        int k;
        cin >> k;
        rep(j, k) {
            int s;
            cin >> s;
            s--;
            SW[s].push_back(i);
        }
    }
    vc<int> p(m, 0);
    rep(i, m) cin >> p[i];
    for (int bit = 0; bit < (1 << n); bit++) {
        vc<int> now(m, 0);
        for (int i = 0; i < n; i++) {
            if (bit & (1 << i)) {
                for (auto sw : SW[i]) {
                    now[sw]++;
                }
            }
        }
        int tmp = 0;
        for (int cn = 0; cn < m; cn++) {
            if (now[cn] % 2 == p[cn]) tmp++;
        }
        if (tmp == m) ans++;
    }
    cout << ans << endl;
}