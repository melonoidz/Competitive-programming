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
    int n, k, l;
    cin >> n >> k >> l;
    atcoder::dsu uf(n + 1);
    map<int, int> cnt;
    rep(i, n + 1) { cnt[i]++; }
    rep(i, k) {
        int p, q;
        cin >> p >> q;
        uf.merge(p, q);
    }
    rep(i, l) {
        int r, s;
        cin >> r >> s;
        if (uf.same(r, s)) {
            cnt[r]++;
            cnt[s]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << cnt[i] << " ";
    }
    cout << endl;
}