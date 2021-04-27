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
int n;
vc<vc<int>> tree(101010);
vc<int> check(101010, 0);
vc<int> ans;
void bfs(int st = 0) {
    priority_queue<int, vc<int>, greater<int>> pq;
    pq.push(st);
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        ans.push_back(p);
        check[p] = 1;
        auto us = tree[p];
        for (auto u : us) {
            if (check[u] == 0) pq.push(u);
        }
    }
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> n;
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    bfs();
    rep(i, ans.size() - 1) cout << ans[i] + 1 << " ";
    cout << ans.back() + 1;
    cout << endl;
}