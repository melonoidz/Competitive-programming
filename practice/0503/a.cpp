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
int numb, numw;
vc<string> s;
vc<vc<int>> seen(410, vc<int>(410, 0));
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
void dfs(int x, int y) {
    seen[x][y] = 1;
    if (s[x][y] == '#')
        numb++;
    else
        numw++;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
        if (s[x][y] == s[nx][ny]) continue;
        if (seen[nx][ny] == 1) continue;
        dfs(nx, ny);
    }
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> h >> w;
    rep(i, h) {
        string g;
        cin >> g;
        s.push_back(g);
    }
    // i+j=2k+1 black, i+j=2k white
    int ans = 0;
    for (int x = 0; x < h; x++) {
        for (int y = 0; y < w; y++) {
            if (s[x][y] == '.' || seen[x][y] == 1) continue;
            numb = 0, numw = 0;
            dfs(x, y);
            ans += numb * numw;
        }
    }
    cout << ans << endl;
}