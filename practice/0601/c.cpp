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
    vvc<int> G(n + m);
    rep(i, n) {
        int k;
        cin >> k;
        rep(j, k) {
            int v;
            cin >> v;
            v--;
            G[i].push_back(v + n);
            G[n + v].push_back(i);
        }
    }
    vc<int> check(n + m, -1);
    queue<int> que;
    que.push(0);
    check[0] = 0;
    while (!que.empty()) {
        auto p = que.front();
        que.pop();
        for (auto u : G[p]) {
            if (check[u] == -1) {
                check[u] = check[p] + 1;
                que.push(u);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (check[i] == -1) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}