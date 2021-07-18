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
    string s, t;
    cin >> s >> t;
    vvc<int> dp(s.length() + 1, vc<int>(t.length() + 1, 0));
    for (int i = 0; i < s.length(); i++) {
        for (int j = 0; j < t.length(); j++) {
            if (s[i] == t[j]) {
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
            } else {
                dp[i + 1][j + 1] =
                    max({dp[i + 1][j + 1], dp[i + 1][j], dp[i][j + 1]});
            }
        }
    }
    string ans;
    int sl = s.length(), tl = t.length();
    while (sl > 0 && tl > 0) {
        if (dp[sl][tl] == dp[sl - 1][tl]) {
            sl--;
        } else if (dp[sl][tl] == dp[sl][tl - 1]) {
            tl--;
        } else {
            ans += s[sl - 1];
            sl--, tl--;
        }
    }
    reverse(ALL(ans));
    cout << ans << endl;
}