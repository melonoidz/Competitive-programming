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
    using mint = atcoder::modint1000000007;
    int n, m;
    cin >> n >> m;
    vc<int> a(n);
    rep(i, n) cin >> a[i];
    vc<int> b(m);
    rep(i, m) cin >> b[i];
    mint ans = 1;
    sort(ALL(a), greater<int>());
    sort(ALL(b), greater<int>());
    int biga = 0, bigb = 0;
    for (int i = n * m; i > 0; i--) {
        if (a[biga] == a[biga + 1]) ans *= 0;
        if (b[bigb] == b[bigb + 1]) ans *= 0;
        if (a[biga] == i && b[bigb] == i) {
            biga++, bigb++;
        } else if (a[biga] == i) {
            ans *= bigb;
            biga++;
        } else if (b[bigb] == i) {
            ans *= biga;
            bigb++;
        } else {
            ans *= max(0LL, biga * bigb - (n * m - i));
        }
        if (ans.val() == 0) {
            cout << ans.val() << endl;
            return 0;
        }
    }
    cout << ans.val() << endl;
}