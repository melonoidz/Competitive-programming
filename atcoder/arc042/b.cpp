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
double dist(pi s, pi g) {
    return sqrt((s.first - g.first) * (s.first - g.first) +
                (s.second - g.second) * (s.second - g.second));
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int x, y;
    cin >> x >> y;
    int n;
    cin >> n;
    double ans = 1e9;
    vc<pi> point;
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        point.emplace_back(a, b);
    }
    point.push_back(point[0]);
    for (int i = 0; i < point.size() - 1; i++) {
        double a = dist(point[i], point[i + 1]);
        double b = dist(pi(x, y), point[i]);
        double c = dist(pi(x, y), point[i + 1]);
        double d = b * b - ((b * b - c * c + a * a) / (2.0 * a)) *
                               ((b * b - c * c + a * a) / (2.0 * a));
        ans = min(ans, d);
    }
    cout << fixed << setprecision(20) << sqrt(ans) << endl;
}