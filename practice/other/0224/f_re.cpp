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
int n, m;
vc<vc<int>> g(1100);
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> n >> m;
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
    }
    int shortest = n + 1;
    vc<int> res;
    for (int i = 0; i < n; i++) {
        vc<int> dist(n, -1);
        vc<int> prev(n, -1);
        queue<int> que;
        que.push(i);
        dist[i] = 0;
        while (!que.empty()) {
            auto v = que.front();
            que.pop();
            for (auto nv : g[v]) {
                if (prev[nv] == -1) {
                    dist[nv] = dist[v] + 1;
                    prev[nv] = v;
                    que.push(nv);
                }
            }
        }
        for (int j = 0; j < n; j++) {
            if (j == i || dist[j] == -1) continue;
            for (auto nj : g[j]) {
                if (nj == i) {
                    vc<int> tmp;
                    tmp.push_back(i);
                    int cur = j;
                    while (cur != i) {
                        tmp.push_back(cur);
                        cur = prev[cur];
                    }
                    if (shortest > tmp.size()) {
                        shortest = tmp.size();
                        res = tmp;
                    }
                }
            }
        }
    }
    if (shortest == n + 1)
        cout << -1 << endl;
    else {
        cout << res.size() << endl;
        for (auto h : res) cout << h + 1 << endl;
    }
}