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

int LCS(const string& a, const string& b) {
    vc<vc<int>> dp(a.size() + 1, vc<int>(b.size() + 1, 0));
    int ans = 0;
    rep(i, a.size()) {
        rep(j, b.size()) {
            if (a[i] == b[j]) {
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
                ans = max(ans, dp[i + 1][j + 1]);
            }
            chmax(dp[i + 1][j], dp[i][j]);
            chmax(dp[i][j + 1], dp[i][j]);
        }
    }
    return ans;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 1LL << 60;
    for (int i = 0; i < n; i++) {
        string a = s.substr(0, i);
        string b = s.substr(i);
        chmin(ans, n - LCS(a, b) * 2);
    }
    cout << ans << endl;
}