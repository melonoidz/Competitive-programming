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
int n, l;
int k;
vc<int> a(100100);
int ch(int x) {
    int cnt = 0;
    int cut = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] - cut >= x && l - a[i] >= x) {
            cut = a[i];
            cnt++;
        }
    }
    return cnt;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> n >> l;
    cin >> k;
    rep(i, n) cin >> a[i];
    int ng = 0;
    int ok = 1e9;
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (ch(mid) >= k) {
            ng = mid;
        } else {
            ok = mid;
        }
    }
    cout << ng << endl;
}