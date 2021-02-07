#include <bits/stdc++.h>
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
int H, W, T;
int sx, sy, gx, gy;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};
vc<string> S;
int solve(int zx, const int sx, const int sy, const int gx, const int gy) {
    queue<pair<pi, int>> que;
    vc<vc<int>> dp(H, vc<int>(W, 1e10));
    dp[sy][sx] = 0;
    vc<vc<bool>> check(H, vc<bool>(W, false));
    que.push(make_pair(make_pair(sx, sy), 0));
    while (!que.empty()) {
        int x = que.front().first.first;
        int y = que.front().first.second;
        int cost = que.front().second;
        que.pop();
        // if(check[y][x]) continue;
        // check[y][x]=true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 > nx || nx >= W || 0 > ny || ny >= H) continue;
            if (S[ny][nx] == '.' || S[ny][nx] == 'S' || S[ny][nx] == 'G') {
                if (dp[ny][nx] <= cost + 1) continue;
                dp[ny][nx] = cost + 1;
                que.push(make_pair(make_pair(nx, ny), dp[ny][nx]));
            } else {
                if (dp[ny][nx] <= cost + zx) continue;
                dp[ny][nx] = cost + zx;
                que.push(make_pair(make_pair(nx, ny), dp[ny][nx]));
            }
        }
    }
    return dp[gy][gx];
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> H >> W >> T;
    rep(i, H) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == 'S') {
                sx = j;
                sy = i;
            }
            if (s[j] == 'G') {
                gx = j;
                gy = i;
            }
        }
        S.push_back(s);
    }
    int ok = -1;
    int ng = T + 10;
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        auto now = solve(mid, sx, sy, gx, gy);
        if (T < now) {
            ng = mid;
        } else {
            ok = mid;
        }
    }
    cout << ok << endl;
    return 0;
}