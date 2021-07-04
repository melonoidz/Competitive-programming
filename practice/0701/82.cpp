#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using mint = atcoder::modint1000000007;
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
mint f(ull x) {
    mint res;
    res = x / 2ULL * (x + 1ULL);
    return res;
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    ull l, r;
    cin >> l >> r;
    mint ans = 0;
    vc<ull> powt(22);
    powt[0] = 1ULL;
    for (int i = 1; i < 20; i++) {
        powt[i] = powt[i - 1] * 10ULL;
    }
    for (auto i = 1; i <= 19; i++) {
        ull vl = max(l, powt[i - 1]);
        ull vr = min(r, powt[i] - 1ULL);
        if (vl > vr) continue;
        mint val = f(vr) - f(vl - 1ULL);
        ans += val * i;
    }
    cout << ans.val() << endl;
    return 0;
}