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
template <typename Func> int findMin(int L, int R, Func f) {  //[L, R)
    int lo = L - 1, hi = R - 1;
    while (lo + 1 != hi) {
        int mi = (lo + hi) / 2;
        if (f(mi) <= f(mi + 1))
            hi = mi;
        else
            lo = mi;
    }
    return hi;
}
int st, sum;
vc<int> a(401010);
int f(int len) {
    int x = a[st + len - 1];
    if (st) x -= a[st - 1];
    int y = sum - x;
    return abs(x - y);
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    rep(i, n) cin >> a[i];
    sum = accumulate(ALL(a), 0LL);
    rep(i, n) a[i + n] = a[i];
    for (int i = 1; i < 2 * n; i++) {
        a[i] += a[i - 1];
    }
    int ans = 1LL << 60;
    for (int i = 0; i < n; i++) {
        st = i;
        int opt = findMin(1, n + 1, f);
        chmin(ans, f(opt));
    }
    cout << ans << endl;
}