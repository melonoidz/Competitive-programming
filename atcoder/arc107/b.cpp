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

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int n, k;
    cin >> n >> k;
    atcoder::dsu ufx(5010);
    atcoder::dsu ufy(5010);
    vc<vc<int>> a(n, vc<int>(n));
    rep(i, n) { rep(j, n) cin >> a[i][j]; }
    const int MOD = 998244353;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            bool flag = true;
            for (int l = 0; l < n; l++) {
                if (a[i][l] + a[j][l] > k) {
                    flag = false;
                }
            }
            if (flag) {
                if (!ufx.same(i + 1, j + 1)) ufx.merge(i + 1, j + 1);
            }
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            bool flag = true;
            for (int l = 0; l < n; l++) {
                if (a[l][i] + a[l][j] > k) {
                    flag = false;
                }
            }
            if (flag) {
                if (!ufy.same(i + 1, j + 1)) ufy.merge(i + 1, j + 1);
            }
        }
    }
    vc<int> flac(150, 0);
    flac[1] = 1;
    for (int i = 1; i < 101; i++) {
        flac[i + 1] = flac[i] * (i + 1) % MOD;
    }
    int dx = 1, dy = 1;
    for (int i = 1; i <= n * n; i++) {
        if (ufx.leader(i) == i) {
            dx *= flac[ufx.size(i)] % MOD;
        }
    }
    for (int i = 1; i <= n * n; i++) {
        if (ufy.leader(i) == i) {
            dy *= flac[ufy.size(i)] % MOD;
        }
    }
    cout << (dx * dy + MOD) % MOD << endl;
    return 0;
}