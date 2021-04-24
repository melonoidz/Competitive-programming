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
int h, w;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};
vc<vc<int>> F(2100, vc<int>(2100, 0));
bool bfs(pi st, pi gl) {
    if (st == gl) return true;
    queue<pi> q;
    q.push(st);
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
            if (F[ny][nx] == 0) continue;
            if (nx == gl.first && ny == gl.second) {
                return true;
            }
            q.push(pi(nx, ny));
        }
    }
    return false;
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> h >> w;
    int q;
    cin >> q;
    rep(i, q) {
        int x;
        cin >> x;
        if (x == 1) {
            int r, c;
            cin >> r >> c;
            r--, c--;
            F[c][r] = 1;
        } else {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            a--, b--, c--, d--;
            if (F[b][a] != 1 || F[d][c] != 1) {
                cout << "No" << endl;
            } else {
                if (bfs(pi(a, b), pi(c, d))) {
                    cout << "Yes" << endl;
                } else {
                    cout << "No" << endl;
                }
            }
        }
    }
}