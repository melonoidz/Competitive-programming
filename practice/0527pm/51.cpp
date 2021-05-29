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
    int n, k, p;
    cin >> n >> k >> p;
    vc<int> a, b;
    rep(i, n) {
        int x;
        cin >> x;
        if (i % 2 == 0)
            a.push_back(x);
        else
            b.push_back(x);
    }
    map<int, vc<int>> Q, Q2;
    int l = b.size();
    for (int bit = 0; bit < (1 << l); bit++) {
        int now = 0;
        int select = popcount(bit);
        for (int i = 0; i < l; i++) {
            if (bit & (1 << i)) {
                now += b[i];
            }
        }
        if (select <= k) {
            Q[select].push_back(now);
        }
    }
    int m = a.size();
    int ans = 0;
    for (int bit = 0; bit < (1 << m); bit++) {
        int now = 0;
        int select = popcount(bit);
        for (int i = 0; i < m; i++) {
            if (bit & (1 << i)) {
                now += a[i];
            }
        }
        if (select <= k) {
            Q2[select].push_back(now);
        }
    }
    rep(i, n + 1) {
        sort(ALL(Q[i]));
        sort(ALL(Q2[i]));
    }
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < Q[i].size(); j++) {
            ans += lower_bound(Q2[k - i].begin(), Q2[k - i].end(),
                               p - Q[i][j] + 1) -
                   Q2[k - i].begin();
        }
    }
    cout << ans << endl;
}