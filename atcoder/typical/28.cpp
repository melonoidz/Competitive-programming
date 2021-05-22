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
vc<vc<int>> cnt(1010, vc<int>(1010, 0));
vc<int> ans(1 << 18), lx(1 << 18), ly(1 << 18), rx(1 << 18), ry(1 << 18);
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> lx[i] >> ly[i] >> rx[i] >> ry[i];
    // Imos
    for (int i = 1; i <= n; i++) {
        cnt[lx[i]][ly[i]]++;
        cnt[lx[i]][ry[i]]--;
        cnt[rx[i]][ly[i]]--;
        cnt[rx[i]][ry[i]]++;
    }
    rep(i, 1001) {
        for (int j = 1; j <= 1000; j++) {
            cnt[i][j] += cnt[i][j - 1];
        }
    }
    for (int i = 1; i <= 1000; i++) {
        rep(j, 1001) { cnt[i][j] += cnt[i - 1][j]; }
    }
    rep(i, 1001) {
        rep(j, 1001) {
            if (cnt[i][j] >= 1) {
                ans[cnt[i][j]]++;
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << endl;
}