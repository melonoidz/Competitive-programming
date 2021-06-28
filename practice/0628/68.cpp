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
    atcoder::dsu uf(100100);
    int n;
    cin >> n;
    int q;
    cin >> q;
    vc<int> t(q), x(q), y(q), v(q);
    rep(i, q) {
        cin >> t[i] >> x[i] >> y[i] >> v[i];
        x[i]--, y[i]--;
    }
    vc<int> sum(n - 1, -1);
    rep(i, q) {
        if (t[i] == 0) {
            sum[x[i]] = v[i];
        }
    }
    vc<int> pot(n, 0);
    // Set管理でもOK
    rep(i, n - 1) { pot[i + 1] = sum[i] - pot[i]; }
    // pot 値を仮定したときの振れ幅
    rep(i, q) {
        if (t[i] == 0) {
            // Type1
            uf.merge(x[i], y[i]);
        } else {
            // Type2
            if (!uf.same(x[i], y[i])) {
                cout << "Ambiguous" << endl;
            } else {
                if ((x[i] + y[i]) % 2 == 0) {
                    // x,yの距離が偶数(1,2,3の1,3)
                    cout << v[i] + pot[y[i]] - pot[x[i]] << endl;
                } else {
                    cout << pot[x[i]] + pot[y[i]] - v[i] << endl;
                }
            }
        }
    }
}