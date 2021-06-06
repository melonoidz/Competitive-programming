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
    int n, s;
    cin >> n >> s;
    vc<pi> load;
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        load.emplace_back(a, b);
    }
    vc<vc<int>> dp(110, vc<int>(100100));
    vc<vc<string>> memo(110, vc<string>(100100));
    dp[0][s] = 1;
    reverse(ALL(load));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 100000; j++) {
            if (dp[i][j] == 1) {
                if (j - load[i].first >= 0) {
                    dp[i + 1][j - load[i].first] = 1;
                    memo[i + 1][j - load[i].first] = "A";
                }
                if (j - load[i].second >= 0) {
                    dp[i + 1][j - load[i].second] = 1;
                    memo[i + 1][j - load[i].second] = "B";
                }
            }
        }
    }
    if (dp[n][0] != 1) {
        cout << "Impossible" << endl;
    } else {
        string ans;
        int st = 0;
        for (int i = n; i > 0; i--) {
            string now = memo[i][st];
            ans += now;
            if (now == "A") {
                st += load[i - 1].first;
            } else {
                st += load[i - 1].second;
            }
        }
        // reverse(ALL(ans));
        cout << ans << endl;
    }
}