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
    // dp:tak-aoki
    // tak (i%2==0) dpを増加
    // aoki dpを減少
    vc<int> a(n), b(n), c(n);
    rep(i, n) cin >> a[i] >> b[i], c[i] = a[i] + b[i];
    int sumb = accumulate(ALL(b), 0LL);
    sort(ALL(c), greater<int>());
    int tak = (n + 1) / 2;
    int ans = -sumb;
    for (int i = 0; i < n; i += 2) {
        ans += c[i];
    }
    cout << ans << endl;
}
