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
int n, m, a, b;
vc<vc<int>> G(1010);
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> n >> m;
    rep(i, m) {
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
    }
    int ans = n + 1;
    vc<int> res;
    for (int s = 0; s < n; s++) {
        vc<int> dist(n, -1);
        vc<int> prev(n, -1);
        queue<int> que;
        que.push(s);
        dist[s] = 0;
        while (!que.empty()) {
            auto v = que.front();
            que.pop();
            for (auto nv : G[v]) {
                if (dist[nv] == -1) {
                    prev[nv] = v;
                    dist[nv] = dist[v] + 1;
                    que.push(nv);
                }
            }
        }
        for (int t = 0; t < n; t++) {
            if (t == s || dist[t] == -1) continue;
            for (auto nt : G[t]) {
                if (nt == s) {
                    vc<int> tmp;
                    tmp.push_back(s);
                    int cur = t;
                    while (cur != s) {
                        tmp.push_back(cur);
                        cur = prev[cur];
                    }
                    if (ans > tmp.size()) {
                        ans = tmp.size();
                        res = tmp;
                    }
                }
            }
        }
    }
    if (ans == n + 1)
        cout << -1 << endl;
    else {
        cout << res.size() << endl;
        for (auto p : res) cout << p + 1 << endl;
    }
}