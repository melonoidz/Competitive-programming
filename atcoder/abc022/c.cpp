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
int N, M;
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    // 0->u->v->0
    // 0に結合しているedgeを除去しておく
    cin >> N >> M;
    vc<pi> zero;
    vc<vc<int>> dist(N, vc<int>(N, 1e9));
    rep(i, M) {
        int u, v, l;
        cin >> u >> v >> l;
        u--, v--;
        if (u == 0) {
            zero.emplace_back(v, l);
            continue;
        }
        dist[u][v] = l;
        dist[v][u] = l;
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int ans = 1e9;
    for (auto st : zero) {
        for (auto gl : zero) {
            if (st.first == gl.first) continue;
            int d = dist[st.first][gl.first] + st.second + gl.second;
            ans = min(ans, d);
        }
    }
    if (ans == 1e9) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}