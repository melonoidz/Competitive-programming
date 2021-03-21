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
const int dx[4] = {0, 1, -1, 0};
const int dy[4] = {1, 0, 0, -1};
int cnt = 0;
const int n = 10;
bool ch = false;
void dfs(vc<vc<char>>& f) {
    for (int i = 0; i < 4; i++) {
        int nx = sx + dx[i];
        int ny = sy + dy[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n || f[ny][nx] == 'x')
            continue;
        if (f[ny][nx] == 'o' && check[ny][nx] == 0) {
            if (ct + 1 == cnt) {
                cout << "YES" << endl;
                ch = true;
                break;
            }
            dfs(f, check, nx, ny, ct + 1);
        }
    }
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    vc<vc<char>> f(n, vc<char>(n));
    rep(i, n) rep(j, n) {
        cin >> f[i][j];
        if (f[i][j] == 'o') {
            cnt++;
        }
    }
    cnt++;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (f[i][j] == 'x') {
                f[i][j] = 'o';
                if (dfs(f)) {
                    cout << "YES" << endl;
                    return 0;
                }
                f[i][j] = 'x';
            }
        }
    }
    cout << "NO" << endl;
}