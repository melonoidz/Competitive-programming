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
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    vc<vc<char>> S(n, vc<char>(n));
    rep(i, n) rep(j, n) cin >> S[i][j];
    int ans = 0;
    rep(x, n) {
        vc<vc<char>> tmp(n, vc<char>(n));
        rep(i, n) rep(j, n) { tmp[i][j] = S[(i + x) % n][j]; }
        bool ok = true;
        for (int ij = 0; ij <= 2 * (n - 1); ij++) {
            bool cur = true;
            for (int aa = 0; aa <= min(n - 1, ij); aa++) {
                if (aa == ij - aa) continue;
                if (ij - aa >= n) continue;
                if (tmp[aa][ij - aa] != tmp[ij - aa][aa]) cur = false;
            }
            if (!cur) ok = false;
        }
        if (ok) ans += n;
    }
    cout << ans << endl;
}