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
int n, m;
int ans = 0;
vc<string> s;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool check(int sx, int sy, vc<string> f) {
    f[sx][sy] = '.';
    int cnt = 0;
    rep(i, n) rep(j, m) {
        if (f[i][j] == '.') cnt++;
    }
    int ok = 0;
    vc<vc<int>> check(11, vc<int>(11, 0));
    queue<pi> q;
    q.push(pi(sx, sy));
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        auto x = p.first;
        auto y = p.second;
        if (check[x][y] == 0) {
            check[x][y] = 1;
            ok++;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (0 > nx || 0 > ny || nx >= n || ny >= m) continue;
                if (check[nx][ny] != 0 || f[nx][ny] == '#') continue;
                q.push(pi(nx, ny));
            }
        }
    }
    return cnt == ok;
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> n >> m;
    rep(i, n) {
        string g;
        cin >> g;
        s.push_back(g);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '#') {
                if (check(i, j, s)) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
}