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
int n, m, v, p;
bool vote(int x, vc<int>& a) {
    const int BORDER = a[p - 1];
    int stock = m * v;
    vc<int> now = a;
    auto b = now[x];
    b += m;
    stock -= m;
    if (BORDER > b) return false;
    for (int i = 0; i < n; i++) {
        if (i == x) continue;
        if (now[i] > BORDER && i < p) {
            stock -= m;
        } else {
            stock -= min(m, b - now[i]);
        }
    }
    return stock <= 0;
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> n >> m >> v >> p;
    vc<int> a(n);
    rep(i, n) cin >> a[i];
    sort(ALL(a), greater<int>());
    int left = 0;
    int right = n;
    while (abs(left - right) > 1) {
        int mid = (left + right) / 2;
        if (vote(mid, a)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    cout << left + 1 << endl;
}