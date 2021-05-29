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
int R, C;
priority_queue<tuple<int, int, int, int>,
               vector<tuple<int, int, int, int>>,
               greater<tuple<int, int, int, int>>>
    q;
void update(int f, int r, int c, int x, vc<vc<vc<int>>>& cost) {
    if (cost[f][r][c] > x) {
        chmin(cost[f][r][c], x);
        q.emplace(x, f, r, c);
    }
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> R >> C;
    const int INF = 1LL << 60;
    vc<vc<int>> A(R, vc<int>(C - 1, 0)), B(R - 1, vc<int>(C, 0));
    for (auto& a : A)
        for (auto& ii : a) cin >> ii;
    for (auto& b : B)
        for (auto& ii : b) cin >> ii;
    vc<vc<vc<int>>> cost(2, vc<vc<int>>(R, vc<int>(C, INF)));
    update(0, 0, 0, 0, cost);
    // x=COST, f=0or1, r=tmpR, c=tmpC
    while (!q.empty()) {
        auto p = q.top();
        q.pop();
        auto [x, f, r, c] = p;
        if (cost[f][r][c] != x) continue;
        if (f) {
            update(0, r, c, x, cost);
            if (r) update(1, r - 1, c, x + 1, cost);
        } else {
            update(1, r, c, x + 1, cost);
            if (r + 1 < R) update(0, r + 1, c, x + B[r][c], cost);
            if (c) update(0, r, c - 1, x + A[r][c - 1], cost);
            if (c + 1 < C) update(0, r, c + 1, x + A[r][c], cost);
        }
    }
    cout << cost.front().back().back() << endl;
}