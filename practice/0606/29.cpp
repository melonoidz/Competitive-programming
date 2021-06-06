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

using S = long long;
using F = long long;

const S INF = 8e18;
const F ID = 8e18;

S op(S a, S b) { return std::max(a, b); }
S e() { return -INF; }
S mapping(F f, S x) { return (f == ID ? x : f); }
F composition(F f, F g) { return (f == ID ? g : f); }
F id() { return ID; }
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int w, n;
    cin >> w >> n;
    vc<int> v(w, 0);
    // s op e f mapping composition id
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> lseg(v);
    // https://atcoder.github.io/ac-library/document_ja/lazysegtree.html
    // https://betrue12.hateblo.jp/entry/2020/09/22/194541
    // https://tsutaj.hatenablog.com/entry/2017/03/30/224339
    rep(i, n) {
        int l, r;
        cin >> l >> r;
        auto height = lseg.prod(l - 1, r) + 1;
        lseg.apply(l - 1, r, height);
        cout << height << endl;
    }
}