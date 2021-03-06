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
int n, m;
vector<int> a(2002000);
bool check(int limit) {
    vc<int> cnt(2002000);
    int exist = 0;
    rep(i, n) cnt[i] = 0;
    for (int i = 0; i < m; i++) {
        if (cnt[a[i]] == 0 && a[i] <= limit) {
            exist++;
        }
        cnt[a[i]]++;
    }
    // exist4個，limit-index=4(==5)
    if (exist <= limit) return true;
    //区間を動かす
    for (int i = m; i < n; i++) {
        //左端の扱い
        if (cnt[a[i - m]] == 1 && a[i - m] <= limit) exist--;
        cnt[a[i - m]]--;
        //右端の扱い
        if (cnt[a[i]] == 0 && a[i] <= limit) {
            exist++;
        }
        cnt[a[i]]++;
        if (exist <= limit) return true;
    }
    return false;
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    int ng = -1, ok = n + 1;
    // limit以下で使われている数を数える． used<=limitならlimit以下のmexがある
    while (abs(ng - ok) > 1) {
        int mid = (ok + ng) / 2;
        if (check(mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    cout << ok << endl;
}