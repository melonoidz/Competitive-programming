#include <bits/stdc++.h>
#include <atcoder/all>
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
int H, W;
int sx, sy, gx, gy;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

vc<string> A;
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> H >> W;
    rep(i, H) {
        string g;
        cin >> g;
        A.push_back(g);
        rep(j, W) {
            if (g[j] == 'S') {
                sx = j, sy = i;
            }
            if (g[j] == 'G') {
                gx = j, gy = i;
            }
        }
    }
    vc<vc<pi>> alcnt(26);
    rep(i, H) {
        rep(j, W) {
            if ('a' <= A[i][j] && A[i][j] <= 'z') {
                alcnt[A[i][j] - 'a'].push_back(make_pair(i, j));
            }
        }
    }
    vc<vc<int>> dp(H, vc<int>(W, 1e9));
    dp[sy][sx] = 0;
    queue<pi> que;
    vc<bool> check(26, false);
    que.push(make_pair(sy, sx));
    while (!que.empty()) {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();
        if ('a' <= A[y][x] && A[y][x] <= 'z') {
            if (!check[A[y][x] - 'a']) {
                for (auto alp : alcnt[A[y][x] - 'a']) {
                    if (dp[alp.first][alp.second] == 1e9) {
                        dp[alp.first][alp.second] = dp[y][x] + 1;
                        que.push(alp);
                    }
                }
                check[A[y][x] - 'a'] = true;
            }
        }
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (0 > ny || ny >= H || 0 > nx || nx >= W || A[ny][nx] == '#')
                continue;
            if (dp[ny][nx] == 1e9) {
                dp[ny][nx] = dp[y][x] + 1;
                que.push(make_pair(ny, nx));
            }
        }
    }
    int ans = dp[gy][gx];
    if (ans == 1e9) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}