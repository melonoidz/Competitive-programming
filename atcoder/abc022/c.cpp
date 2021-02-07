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
    vc<vc<pi>> G(N);
    vc<vc<pi>> GW(N);
    rep(i, M) {
        int u, v, l;
        cin >> u >> v >> l;
        u--, v--;
        G[u].push_back(pi(v, l));
        G[v].push_back(pi(u, l));
        if (!(u == 0 || v == 0)) {
            GW[u].push_back(pi(v, l));
            GW[v].push_back(pi(u, l));
        }
    }
    vc<vc<int>> dist(N, vc<int>(N, 1e9));
    for (int i = 0; i < GW.size(); i++) {
        for (int j = 0; j < GW[i].size(); j++) {
            dist[i][GW[i][j].first] = GW[i][j].second;
            dist[GW[i][j].first][i] = GW[i][j].second;
        }
    }
    for (int i = 1; i < N; i++) {
        for (int k = 1; k < N; k++) {
            for (int j = 1; j < N; j++) {
                if (i == j) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int ans = 1e10;
    auto start = G[0];
    for (int i = 0; i < start.size() - 1; i++) {
        for (int j = i + 1; j < start.size(); j++) {
            if (dist[start[i].first][start[j].first] != 1e9) {
                int tmp = start[i].second + start[j].second +
                          dist[start[i].first][start[j].first];
                ans = min(ans, tmp);
            }
        }
    }
    if (ans == 1e10) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}