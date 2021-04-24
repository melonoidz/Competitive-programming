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
    vc<int> poi(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        poi[x] = i;
    }
    int ans = 0;
    multiset<int> used;
    used.insert(0);
    used.insert(0);
    used.insert(n + 1);
    used.insert(n + 1);
    for (int i = n; i > 0; i--) {
        used.insert(poi[i]);
        auto itr = used.lower_bound(poi[i]);
        auto l1 = prev(itr);
        auto l2 = prev(l1);
        auto r1 = next(itr);
        auto r2 = next(r1);
        auto cnt = (*l1 - *l2) * (*r1 - poi[i]) + (poi[i] - *l1) * (*r2 - *r1);
        ans += i * cnt;
    }
    cout << ans << endl;
}