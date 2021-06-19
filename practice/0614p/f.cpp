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
int dx[]{1, -1, 0, 0};
int dy[]{0, 0, 1, -1};
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int h, w, k;
    cin >> h >> w >> k;
    int sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    sx--, sy--, gx--, gy--;
    vc<string> C;
    rep(i, h) {
        string g;
        cin >> g;
        C.push_back(g);
    }
    vc<vc<int>> dist(h, vc<int>(w, 1LL << 60));
    vc<vc<bool>> used(h, vc<bool>(w, false));
    dist[sx][sy] = 0;
    queue<pair<pi, int>> que;
    que.push(make_pair(pi(sx, sy), dist[sx][sy]));
    while (!que.empty()) {
        auto p = que.front();
        que.pop();
        auto x = p.first.first;
        auto y = p.first.second;
        auto cost = p.second;
        if (x == gx && y == gy) {
            cout << cost << endl;
            return 0;
        }
        rep(i, 4) {
            int nx = x, ny = y;
            rep(j, k) {
                nx += dx[i];
                ny += dy[i];
                if (nx < 0 || ny < 0 || nx >= h || ny >= w) break;
                if (C[nx][ny] == '@') break;
                if (used[nx][ny] && dist[nx][ny] <= cost)
                    break;  //枝刈りできる==の場合
                if (!used[nx][ny]) {
                    used[nx][ny] = true;
                    dist[nx][ny] = cost + 1;
                    que.push(make_pair(pi(nx, ny), cost + 1));
                }
            }
        }
    }
    cout << -1 << endl;
}