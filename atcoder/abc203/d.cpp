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
int n, k;
bool check(int x, vc<vc<int>> a) {
    vc<vc<int>> now(810, vc<int>(810, 0));
    rep(i, n) {
        rep(j, n) {
            if (a[i][j] <= x) {
                now[i][j] = 1;
            }
        }
    }
    vc<vc<int>> s(810, vc<int>(810, 0));
    rep(i, n) {
        rep(j, n) {
            s[i + 1][j + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j] + now[i][j];
        }
    }
    for (int i = 0; i <= n - k; i++) {
        for (int j = 0; j <= n - k; j++) {
            int cnt = s[i + k][j + k] + s[i][j] - s[i][j + k] - s[i + k][j];
            if (cnt > k * k - ((k * k) / 2 + 1)) {
                return true;
            }
        }
    }
    return false;
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> n >> k;
    vc<vc<int>> a(n, vc<int>(n));
    set<int> num;
    rep(i, n) { rep(j, n) cin >> a[i][j], num.insert(a[i][j]); }
    vc<int> u(ALL(num));
    int ng = -1;
    int ok = u.size();
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (check(u[mid], a)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    cout << u[ok] << endl;
}