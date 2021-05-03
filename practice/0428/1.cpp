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
int sx, sy, gx, gy;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
map<pair<pi, int>, int> walk;
vc<string> c;
bool bfs(pi a, pi b, int cnt = 2) {
    queue<pair<pi, int>> q;
    q.push(make_pair(a, cnt));
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        auto ncnt = p.second;
        auto nx = p.first.first;
        auto ny = p.first.second;
        walk[make_pair(pi(nx, ny), ncnt)]++;
        for (int j = 0; j < 4; j++) {
            int tx = nx + dx[j];
            int ty = ny + dy[j];
            walk[make_pair(pi(tx, ty), ncnt)]++;
            if (walk[make_pair(pi(tx, ty), ncnt)] < 2) {
                if (tx < 0 || ty < 0 || tx >= w || ty >= h) continue;
                if (c[ty][tx] == '#') {
                    if (ncnt > 0) {
                        q.push(make_pair(pi(tx, ty), ncnt - 1));
                    }
                }
                if (c[ty][tx] == '.') {
                    q.push(make_pair(pi(tx, ty), ncnt));
                }
                if (tx == b.first && ty == b.second) return true;
            }
        }
    }
    return false;
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> h >> w;
    rep(i, h) {
        string g;
        cin >> g;
        c.push_back(g);
        for (int j = 0; j < g.length(); j++) {
            if (g[j] == 's') {
                sx = j;
                sy = i;
            }
            if (g[j] == 'g') {
                gx = j;
                gy = i;
            }
        }
    }
    if (bfs(pi(sx, sy), pi(gx, gy))) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}