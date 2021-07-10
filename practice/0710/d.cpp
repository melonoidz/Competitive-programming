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
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int h, w, n;
    cin >> h >> w >> n;
    vc<int> cnt(10, 0);
    map<pi, int> grid;
    vc<pi> p(n);
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        grid[pi(a, b)] = 1;
        p[i] = pi(a, b);
    }
    for (auto u : p) {
        int nx = u.first;
        int ny = u.second;
        //[0,0]
        int tmp = 0;
        if (nx >= 0 && nx + 2 < h && ny + 2 < w && ny >= 0) {
            if (grid[pi(nx, ny)] == 1) tmp++;
            if (grid[pi(nx + 1, ny)] == 1) tmp++;
            if (grid[pi(nx + 2, ny)] == 1) tmp++;
            if (grid[pi(nx, ny + 1)] == 1) tmp++;
            if (grid[pi(nx + 1, ny + 1)] == 1) tmp++;
            if (grid[pi(nx + 2, ny + 1)] == 1) tmp++;
            if (grid[pi(nx, ny + 2)] == 1) tmp++;
            if (grid[pi(nx + 1, ny + 2)] == 1) tmp++;
            if (grid[pi(nx + 2, ny + 2)] == 1) tmp++;
            // cout << "[0,0]" << endl;
            // cout << nx << " " << ny << " " << tmp << endl;
            cnt[tmp]++;
        }
        //[0,1]
        tmp = 0;
        if (nx - 1 >= 0 && nx + 1 < h && ny + 2 < w && ny >= 0) {
            if (grid[pi(nx, ny)] == 1) tmp++;
            if (grid[pi(nx + 1, ny)] == 1) tmp++;
            if (grid[pi(nx - 1, ny)] == 1) tmp++;
            if (grid[pi(nx, ny + 1)] == 1) tmp++;
            if (grid[pi(nx + 1, ny + 1)] == 1) tmp++;
            if (grid[pi(nx - 1, ny + 1)] == 1) tmp++;
            if (grid[pi(nx, ny + 2)] == 1) tmp++;
            if (grid[pi(nx + 1, ny + 2)] == 1) tmp++;
            if (grid[pi(nx - 1, ny + 2)] == 1) tmp++;
            // cout << "[0,1]" << endl;
            // cout << nx << " " << ny << " " << tmp << endl;
            cnt[tmp]++;
        }
        //[0,2]
        tmp = 0;
        if (nx - 2 >= 0 && nx < h && ny + 2 < w && ny >= 0) {
            if (grid[pi(nx, ny)] == 1) tmp++;
            if (grid[pi(nx - 1, ny)] == 1) tmp++;
            if (grid[pi(nx - 2, ny)] == 1) tmp++;
            if (grid[pi(nx, ny + 1)] == 1) tmp++;
            if (grid[pi(nx - 1, ny + 1)] == 1) tmp++;
            if (grid[pi(nx - 2, ny + 1)] == 1) tmp++;
            if (grid[pi(nx, ny + 2)] == 1) tmp++;
            if (grid[pi(nx - 1, ny + 2)] == 1) tmp++;
            if (grid[pi(nx - 2, ny + 2)] == 1) tmp++;
            // cout << "[0,2]" << endl;
            // cout << nx << " " << ny << " " << tmp << endl;
            cnt[tmp]++;
        }
        //[1,0]
        tmp = 0;
        if (nx >= 0 && nx + 2 < h && ny + 1 < w && ny - 1 >= 0) {
            if (grid[pi(nx, ny - 1)] == 1) tmp++;
            if (grid[pi(nx + 1, ny - 1)] == 1) tmp++;
            if (grid[pi(nx + 2, ny - 1)] == 1) tmp++;
            if (grid[pi(nx, ny + 1)] == 1) tmp++;
            if (grid[pi(nx + 1, ny + 1)] == 1) tmp++;
            if (grid[pi(nx + 2, ny + 1)] == 1) tmp++;
            if (grid[pi(nx, ny)] == 1) tmp++;
            if (grid[pi(nx + 1, ny)] == 1) tmp++;
            if (grid[pi(nx + 2, ny)] == 1) tmp++;
            // cout << "[1,0]" << endl;
            // cout << nx << " " << ny << " " << tmp << endl;
            cnt[tmp]++;
        }
        //[1,1]
        tmp = 0;
        if (nx - 1 >= 0 && nx + 1 < h && ny + 1 < w && ny - 1 >= 0) {
            if (grid[pi(nx, ny)] == 1) tmp++;
            if (grid[pi(nx + 1, ny)] == 1) tmp++;
            if (grid[pi(nx - 1, ny)] == 1) tmp++;
            if (grid[pi(nx, ny + 1)] == 1) tmp++;
            if (grid[pi(nx + 1, ny + 1)] == 1) tmp++;
            if (grid[pi(nx - 1, ny + 1)] == 1) tmp++;
            if (grid[pi(nx, ny - 1)] == 1) tmp++;
            if (grid[pi(nx + 1, ny - 1)] == 1) tmp++;
            if (grid[pi(nx - 1, ny - 1)] == 1) tmp++;
            // cout << "[1,1]" << endl;
            // cout << nx << " " << ny << " " << tmp << endl;
            cnt[tmp]++;
        }
        //[1,2]
        tmp = 0;
        if (nx - 2 >= 0 && nx < h && ny + 1 < w && ny - 1 >= 0) {
            if (grid[pi(nx, ny)] == 1) tmp++;
            if (grid[pi(nx - 1, ny)] == 1) tmp++;
            if (grid[pi(nx - 2, ny)] == 1) tmp++;
            if (grid[pi(nx, ny + 1)] == 1) tmp++;
            if (grid[pi(nx - 1, ny + 1)] == 1) tmp++;
            if (grid[pi(nx - 2, ny + 1)] == 1) tmp++;
            if (grid[pi(nx, ny - 1)] == 1) tmp++;
            if (grid[pi(nx - 1, ny - 1)] == 1) tmp++;
            if (grid[pi(nx - 2, ny - 1)] == 1) tmp++;
            // cout << "[1,2]" << endl;
            // cout << nx << " " << ny << " " << tmp << endl;
            cnt[tmp]++;
        }
        //[2,0]
        tmp = 0;
        if (nx >= 0 && nx + 2 < h && ny < w && ny - 2 >= 0) {
            if (grid[pi(nx, ny)] == 1) tmp++;
            if (grid[pi(nx + 1, ny)] == 1) tmp++;
            if (grid[pi(nx + 2, ny)] == 1) tmp++;
            if (grid[pi(nx, ny - 1)] == 1) tmp++;
            if (grid[pi(nx + 1, ny - 1)] == 1) tmp++;
            if (grid[pi(nx + 2, ny - 1)] == 1) tmp++;
            if (grid[pi(nx, ny - 2)] == 1) tmp++;
            if (grid[pi(nx + 1, ny - 2)] == 1) tmp++;
            if (grid[pi(nx + 2, ny - 2)] == 1) tmp++;
            // cout << "[2,0]" << endl;
            // cout << nx << " " << ny << " " << tmp << endl;
            cnt[tmp]++;
        }
        //[2,1]
        tmp = 0;
        if (nx - 1 >= 0 && nx + 1 < h && ny < w && ny - 2 >= 0) {
            if (grid[pi(nx, ny)] == 1) tmp++;
            if (grid[pi(nx + 1, ny)] == 1) tmp++;
            if (grid[pi(nx - 1, ny)] == 1) tmp++;
            if (grid[pi(nx, ny - 1)] == 1) tmp++;
            if (grid[pi(nx + 1, ny - 1)] == 1) tmp++;
            if (grid[pi(nx - 1, ny - 1)] == 1) tmp++;
            if (grid[pi(nx, ny - 2)] == 1) tmp++;
            if (grid[pi(nx + 1, ny - 2)] == 1) tmp++;
            if (grid[pi(nx - 1, ny - 2)] == 1) tmp++;
            // cout << "[2,1]" << endl;
            // cout << nx << " " << ny << " " << tmp << endl;
            cnt[tmp]++;
        }
        //[2,2]
        tmp = 0;
        if (nx - 2 >= 0 && nx < h && ny < w && ny - 2 >= 0) {
            if (grid[pi(nx, ny)] == 1) tmp++;
            if (grid[pi(nx - 1, ny)] == 1) tmp++;
            if (grid[pi(nx - 2, ny)] == 1) tmp++;
            if (grid[pi(nx, ny - 1)] == 1) tmp++;
            if (grid[pi(nx - 1, ny - 1)] == 1) tmp++;
            if (grid[pi(nx - 2, ny - 1)] == 1) tmp++;
            if (grid[pi(nx, ny - 2)] == 1) tmp++;
            if (grid[pi(nx - 1, ny - 2)] == 1) tmp++;
            if (grid[pi(nx - 2, ny - 2)] == 1) tmp++;
            // cout << "[2,2]" << endl;
            // cout << nx << " " << ny << " " << tmp << endl;
            cnt[tmp]++;
        }
    }
    for (int i = 1; i < 10; i++) {
        cnt[i] /= i;
    }
    int sum = accumulate(ALL(cnt), 0LL);
    cnt[0] = ((h - 2) * (w - 2)) - sum;
    rep(i, 10) cout << cnt[i] << endl;
}