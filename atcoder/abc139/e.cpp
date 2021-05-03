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
vc<vc<int>> path(1100);
vc<vc<int>> a(1100, vc<int>(1100));
map<pi, int> ind;
int res = 0;
void dfs(int st, int p = -1, int cnt = 0) {
    chmax(res, cnt);
    for (auto u : path[st - 1]) {
        if (u != p) {
            dfs(u, st, cnt + 1);
        }
    }
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> n;
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            ind[pi(i, j)] = cnt;
            ind[pi(j, i)] = cnt;
            cnt++;
        }
    }
    for (int i = 1; i <= n; i++) {
        int bef = -1;
        for (int j = 1; j < n; j++) {
            int t;
            cin >> t;
            a[i][j] = t;
            int game = ind[pi(i, t)];
            if (bef == -1) {
                bef = game;
            } else {
                path[game].push_back(bef);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        dfs(ind[pi(i, a[i][1])]);
        chmax(ans, res);
        res = 0;
    }
    cout << ans << endl;
}