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
vvc<int> a(810, vc<int>(810));
bool jud(int x) {
    vvc<int> hist(810, vc<int>(810, 0));
    rep(i, n) rep(j, n) { hist[i][j] = (a[i][j] <= x); }
    vvc<int> imos(810, vc<int>(810));
    rep(i, n) {
        rep(j, n) {
            imos[i + 1][j + 1] =
                imos[i][j + 1] + imos[i + 1][j] - imos[i][j] + hist[i][j];
        }
    }
    for (int i = 0; i <= n - k; i++) {
        for (int j = 0; j <= n - k; j++) {
            int cnt = imos[i + k][j + k] + imos[i][j] - imos[i + k][j] -
                      imos[i][j + k];
            if (cnt > k * k - (k * k / 2 + 1)) {
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
    set<int> d;
    rep(i, n) rep(j, n) cin >> a[i][j], d.insert(a[i][j]);
    vc<int> ds(ALL(d));
    int ng = -1;
    int ok = ds.size();
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (jud(ds[mid])) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    cout << ds[ok] << endl;
}