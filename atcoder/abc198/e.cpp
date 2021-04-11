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
vc<int> check(100100, 0);
vc<int> ng, ok;
vc<vc<int>> t;
vc<int> c;
void bfs(int st, int dist) {
    queue<pi> pq;
    pq.push(pi(st, dist));
    ng[c[st]] = dist;
    ok[st] = 1;
    while (!pq.empty()) {
        auto p = pq.front();
        pq.pop();
        int now = p.first;
        int d = p.second;
        for (auto u : t[now]) {
            if (!check[u]) {
                check[u] = 1;
                if (ng[c[u]] >= d + 1) {
                    ng[c[u]] = d + 1;
                    ok[u] = 1;
                }
                pq.push(pi(u, d + 1));
            }
        }
    }
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    c.resize(100100);
    ng.resize(100100, 1e18);
    ok.resize(100100, 0);
    rep(i, n) cin >> c[i];
    t.resize(100100);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        t[a].push_back(b);
        t[b].push_back(a);
    }
    bfs(0, 0);
    for (int i = 0; i < n; i++) {
        if (ok[i] == 1) {
            cout << i + 1 << endl;
        }
    }
}