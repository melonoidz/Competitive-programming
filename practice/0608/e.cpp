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
    vc<int> check(2, 0), c(n);
    rep(i, n) {
        cin >> c[i];
        check[c[i]]++;
    }
    if (check[0] == 0 || check[1] == 0) {
        cout << -1 << endl;
        return 0;
    }
    vc<int> range;
    int now = c[0];
    int cnt = 1;
    c.push_back(2);
    for (int i = 1; i <= n; i++) {
        if (c[i] == now) {
            cnt++;
        } else {
            range.push_back(cnt);
            cnt = 1;
            now = c[i];
        }
    }
    if (c[0] == c[n - 1]) {
        int nt = range.front() + range.back();
        range.push_back(nt);
    }
    int ans = 0;
    for (auto r : range) {
        chmax(ans, r);
    }
    if (ans < 3)
        cout << 1 << endl;
    else {
        cout << (ans - 1) / 2 + 1 << endl;
    }
}