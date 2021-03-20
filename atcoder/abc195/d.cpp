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
    int n, m, q;
    cin >> n >> m >> q;
    vc<pi> l(n);
    int sul = 0;
    rep(i, n) {
        int w, v;
        cin >> w >> v;
        l[i].first = w;
        l[i].second = v;
        sul += v;
    }
    vc<int> x(m);
    rep(i, m) cin >> x[i];
    vc<vc<int>> dp(m + 1, vc<int>(m + 1));
    rep(i, m + 1) { dp[i][i] = 0; }
    for (int i = 0; i < m - 1; i++) {
        vc<int> nb;
        nb.push_back(x[i]);
        for (int j = i + 1; j < m; j++) {
            nb.push_back(x[j]);
            map<int, int> load;
            sort(ALL(nb));
            vc<int> ch(n, 0);
            for (auto b : nb) {
                load[b] = 1e18;
                int tmp = 0;
                for (int k = 0; k < n; k++) {
                    if (b >= l[k].first) {
                        if (load[b] > l[k].second && ch[k] != 1) {
                            load[b] = l[k].second;
                            tmp = k;
                     
                        }
                    }
                }
                ch[tmp] = 1;
            }
            int res = 0;
            for (auto y : load) {
                res += y.second;
            }
            dp[i][j] = res;
        }
    }

    rep(aa, q) {
        int L, R;
        cin >> L >> R;
        L--, R--;
        cout << sul - dp[L][R] << endl;
    }
}