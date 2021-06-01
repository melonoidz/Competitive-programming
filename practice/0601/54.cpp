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
    vc<vc<int>> G(n + m);
    rep(i, m) {
        int k;
        cin >> k;
        rep(j, k) {
            int v;
            cin >> v;
            v--;
            G[v].push_back(n + i);
            G[n + i].push_back(v);
        }
    }
    queue<int> que;
    que.push(0);
    vc<int> dist(n + m, -2);
    dist[0] = 0;
    while (!que.empty()) {
        auto u = que.front();
        que.pop();
        for (auto i : G[u]) {
            if (dist[i] == -2) {
                dist[i] = dist[u] + 1;
                que.push(i);
            }
        }
    }
    rep(i, n) { cout << dist[i] / 2 << endl; }
}