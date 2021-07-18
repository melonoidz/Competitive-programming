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
    int n, k;
    cin >> n >> k;
    vc<int> c(n);
    rep(i, n) cin >> c[i];
    map<int, int> cnt;
    int ans = 0;
    for (int i = 0; i < k; i++) {
        cnt[c[i]]++;
        if (cnt[c[i]] == 1) ans++;
    }
    int kind = ans;
    for (int i = 1; i < n - k + 1; i++) {
        int tmp = kind;
        cnt[c[i + k - 1]]++;
        if (cnt[c[i + k - 1]] == 1) {
            tmp++;
        }
        cnt[c[i - 1]]--;
        if (cnt[c[i - 1]] == 0) tmp--;
        chmax(ans, tmp);
        kind = tmp;
    }
    cout << ans << endl;
}