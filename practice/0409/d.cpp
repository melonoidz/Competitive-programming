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
    int ans = 0;
    int n;
    cin >> n;
    if (n < 10) {
        cout << 1 << endl;
        return 0;
    }
    vc<vc<int>> cnt(10, vc<int>(10, 0));
    for (int i = 1; i <= n; i++) {
        string num = to_string(i);
        cnt[num.front() - '0'][num.back() - '0']++;
    }
    for (int t = 1; t < 10; t++) {
        for (int b = 1; b < 10; b++) {
            ans += cnt[t][b] * cnt[b][t];
        }
    }
    cout << ans << endl;
}