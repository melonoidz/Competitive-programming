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

double f(double x, vc<int>& a) {
    double res = 0.0;
    for (auto u : a) {
        double v = double(u);
        res += x + v - min(v, 2.0 * x);
    }
    return res;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vc<int> a(n);
    rep(i, n) cin >> a[i];
    int ma = *max_element(ALL(a));
    int calc = 200;
    double low = 0.0;
    double high = double(ma);
    while (calc--) {
        double c1 = (low * 2.0 + high) / 3.0;
        double c2 = (low + high * 2.0) / 3.0;
        double n1 = f(low, a);
        double n2 = f(high, a);
        if (n1 > n2)
            low = c1;
        else
            high = c2;
    }
    cout << f(low, a) / double(n) << endl;
}