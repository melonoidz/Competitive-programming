#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
#define int ll
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
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
    int n, k;
    cin >> n >> k;
    vc<int> a(n, 0);
    rep(i, n) cin >> a[i];
    map<int, int> tmp;
    rep(i, n) { tmp[a[i]]++; }
    int ans = 0;
    int num = 1;
    int cnt = min(k, tmp[0]);
    int ma = *max_element(a.begin(), a.end());
    while (cnt > 0) {
        if (tmp[num] == 0) {
            ans += num * cnt;
            break;
        }
        if (tmp[num] < cnt) {
            ans += (cnt - tmp[num]) * num;
            cnt = tmp[num];
        }
        num++;
        if (num == ma + 1) {
            ans += cnt * num;
            break;
        }
    }
    cout << ans << endl;
}