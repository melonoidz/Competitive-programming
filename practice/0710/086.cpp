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
    int n, q;
    cin >> n >> q;
    using mint = atcoder::modint1000000007;
    mint ans = 1;
    vc<int> x(q), y(q), z(q), w(q);
    rep(i, q) cin >> x[i] >> y[i] >> z[i] >> w[i];
    for (int dig = 0; dig < 60; dig++) {
        vc<int> nw(q);
        for (int j = 0; j < q; j++) {
            nw[j] = (w[j] / (1LL << dig)) % 2LL;  //その桁のbit
        }
        int ret = 0;
        for (int i = 0; i < (1 << n); i++) {
            vc<int> bit(15);
            for (int j = 0; j < n; j++) {
                bit[j + 1] = (i / (1 << j)) % 2;
            }
            bool f = true;
            rep(j, q) {
                if ((bit[x[j]] | bit[y[j]] | bit[z[j]]) != nw[j]) f = false;
            }
            if (f) ret++;
        }
        ans *= ret;
    }
    cout << ans.val() << endl;
}
