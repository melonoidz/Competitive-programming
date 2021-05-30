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
    vc<int> a(n), b(n), res(n);
    map<int, queue<int>> ind;
    rep(i, n) cin >> a[i];
    rep(i, n) {
        cin >> b[i];
        ind[b[i] + i].push(i);
    }
    rep(i, n) {
        a[i] += i;
        auto& q = ind[a[i]];
        if (q.empty()) {
            cout << -1 << endl;
            return 0;
        }
        auto id = q.front();
        q.pop();
        res[i] = id;
    }
    int ans = 0;
    atcoder::fenwick_tree<int> bit(n);
    for (int i = 0; i < n; i++) {
        ans += bit.sum(res[i], n);
        bit.add(res[i], 1);
    }
    cout << ans << endl;
}