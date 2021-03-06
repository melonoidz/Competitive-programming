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
    vc<string> s;
    vc<pi> delta{pi(1, 0),   pi(-1, 0), pi(0, 1), pi(0, -1), pi(0, 0),
                 pi(-1, -1), pi(-1, 1), pi(1, 1), pi(1, -1)};
    rep(i, n) {
        string g;
        cin >> g;
        s.push_back(g);
    }
    vc<vc<int>> ans(n, vc<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x = i, y = j;
            int cnt = 0;
            for (auto d : delta) {
                int nx = x + d.first;
                int ny = y + d.second;
                if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                    if (s[nx][ny] == '#') cnt++;
                }
            }
            ans[i][j] = cnt;
        }
    }
    rep(i, n) {
        rep(j, m) cout << ans[i][j];
        cout << endl;
    }
}