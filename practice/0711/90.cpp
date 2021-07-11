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

using mint = atcoder::modint998244353;

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int n, k;
    cin >> n >> k;
    mint ans = 0;
    vc<int> pows(10);
    pows[0] = 1;
    rep(i, 8) { pows[i + 1] = pows[i] * 7; }
    for (int bit = 0; bit < pows[n]; bit++) {
        vc<int> now(n);
        int tmp = bit;
        for (int i = 0; i < n; i++) {
            int cur = tmp % 7;
            now[i] = cur;
            tmp /= 7;
        }
        bool ok = true;
        for (int x = 0; x < n; x++) {
            int st = now[x];
            for (int y = x; y < n; y++) {
                chmin(st, now[y]);
                if (st * (y - x + 1) > k) ok = false;
            }
        }
        if (ok) ans++;
    }
    cout << ans.val() << endl;
}