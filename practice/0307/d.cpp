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

int H, W;
vc<string> f(100);
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};
int bfs(pi now) {
    int cnt = 0;
    queue<pair<pi, int>> que;
    vc<vc<int>> dist(100, vc<int>(100, -1));
    dist[0][0] = cnt;
    que.push(make_pair(now, cnt));
    while (!que.empty()) {
        auto p = que.front();
        que.pop();
        int x = p.first.first;
        int y = p.first.second;
        int nowcnt = p.second;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 > nx || nx >= W || 0 > ny || ny >= H || f[ny][nx] == '#')
                continue;
            if (dist[ny][nx] == -1) {
                dist[ny][nx] = nowcnt + 1;
                que.push(make_pair(pi(nx, ny), dist[ny][nx]));
            }
        }
    }

    return dist[H - 1][W - 1];
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> H >> W;
    int bcnt = 0;
    rep(i, H) {
        cin >> f[i];
        for (auto j : f[i]) {
            if (j == '#') bcnt++;
        }
    }
    int dist = bfs(pi(0, 0));
    if (dist == -1) {
        cout << -1 << endl;
    } else {
        int ans = H * W - (dist + 1) - bcnt;
        cout << max(ans, 0LL) << endl;
    }
}