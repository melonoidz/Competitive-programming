#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg, x.ed
#define si(x) int(x.size())
#ifdef LOCAL
#else
#define dmp(x) void(0)
#endif
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
#define mp make_pair
#define mt make_tuple
#define one(x) memset(x, -1, sizeof(x))
#define zero(x) memset(x, 0, sizeof(x))
#ifdef LOCAL
void dmpr(ostream& os) { os << endl; }
template <class T, class... Args>
void dmpr(ostream& os, const T& t, const Args&... args) {
    os << t << ;
    dmpr(os, args...);
}
#define dmp2(...) dmpr(cerr, __LINE__, ##__VA_ARGS__)
#else
#define dmp2(...) void(0)
#endif
using uint = unsigned;
using ull = unsigned long long;
template <class t, size_t n>
ostream& operator<<(ostream& os, const array<t, n>& a) {
    return os << vc<t>(all(a));
}
template <class T> void print(const vector<T>& v, int suc = 1) {
    rep(i, v.size()) print(v[i], i == int(v.size()) - 1 ? suc : 2);
}
template <class T> T sq(const T& t) { return t * t; }
constexpr ll ten(int n) { return n == 0 ? 1 : ten(n - 1) * 10; }
const ll infLL = LLONG_MAX / 3;
#ifdef int
const int inf = infLL;
#else
const int inf = INT_MAX / 2 - 100;
#endif
int topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
int topbit(ll t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
int botbit(signed a) { return a == 0 ? 32 : __builtin_ctz(a); }
int botbit(ll a) { return a == 0 ? 64 : __builtin_ctzll(a); }
int popcount(signed t) { return __builtin_popcount(t); }
int popcount(ll t) { return __builtin_popcountll(t); }
bool ispow2(int i) { return i && (i & -i) == i; }
ll mask(int i) { return (ll(1) << i) - 1; }
template <class t> int lwb(const vc<t>& v, const t& a) {
    return lower_bound(all(v), a) - v.bg;
}
int lcm(int a, int b) { return a / __gcd(a, b) * b; }
const vc<int> dx = {1, 0, -1, 0};
const vc<int> dy = {0, 1, 0, -1};
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int h, w;
    cin >> h >> w;
    vc<string> f;
    int sx, sy;
    int tx, ty;
    rep(i, h) {
        string g;
        cin >> g;
        f.push_back(g);
        rep(j, w) {
            if (g[j] == 'S') {
                sx = j, sy = i;
            }
            if (g[j] == 'G') {
                tx = j, ty = i;
            }
        }
    }
    vc<vc<pi>> pl(26);
    rep(i, h) {
        rep(j, w) {
            if (f[i][j] >= 'a' && f[i][j] <= 'z') {
                pl[f[i][j] - 'a'].emplace_back(i, j);
            }
        }
    }
    vc<vc<int>> dp(2010, vc<int>(2010, -1));
    dp[sy][sx] = 0;
    vc<bool> check(26, false);
    queue<pi> que;
    que.push(pi(sy, sx));
    while (!que.empty()) {
        auto tmp = que.front();
        que.pop();
        int y = tmp.first;
        int x = tmp.second;
        if (f[y][x] >= 'a' && f[y][x] <= 'z') {
            int c = f[y][x] - 'a';
            if (!check[c]) {
                for (auto p : pl[c]) {
                    if (dp[p.first][p.second] == -1) {
                        dp[p.first][p.second] = dp[y][x] + 1;
                        que.push(p);
                    }
                }
            }
            check[c] = true;
        }
        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];
            if (0 > ny || ny >= h || 0 > nx || nx >= w || f[ny][nx] == '#')
                continue;
            if (dp[ny][nx] == -1) {
                dp[ny][nx] = dp[y][x] + 1;
                que.push(pi(ny, nx));
            }
        }
    }
    cout << dp[ty][tx] << endl;
}