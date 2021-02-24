#include <bits/stdc++.h>
#include <atcoder/all>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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
vc<vc<int>> G(1100);
int N, M;
int A, B;
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> N >> M;
    rep(i, M) {
        cin >> A >> B;
        A--, B--;
        G[A].push_back(B);
    }
    int shortest = N + 1;
    vc<int> res;
    for (int s = 0; s < N; s++) {
        vc<int> dist(N, -1);
        vc<int> prev(N, -1);
        queue<int> que;
        que.push(s);
        dist[s] = 0;
        while (!que.empty()) {
            auto v = que.front();
            que.pop();
            for (auto nv : G[v]) {
                if (dist[nv] == -1) {
                    dist[nv] = dist[v] + 1;
                    prev[nv] = v;
                    que.push(nv);
                }
            }
        }
        for (int t = 0; t < N; t++) {
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
                    if (shortest > tmp.size()) {
                        shortest = tmp.size();
                        res = tmp;
                    }
                }
            }
        }
    }
    if (shortest == N + 1) {
        cout << -1 << endl;
    } else {
        cout << res.size() << endl;
        for (auto u : res) cout << u + 1 << endl;
    }
}