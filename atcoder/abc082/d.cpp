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
int dp[8100][16180] = {0};
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    string s;
    cin >> s;
    s += 'T';
    int x, y;
    cin >> x >> y;
    vc<int> X;
    vc<int> Y;
    bool f = true;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'T' && i == 0) {
            X.push_back(0);
            f = false;
        } else {
            if (s[i] == 'F') {
                cnt++;
            } else {
                if (f) {
                    X.push_back(cnt);
                    cnt = 0;
                    f = false;
                } else {
                    Y.push_back(cnt);
                    cnt = 0;
                    f = true;
                }
            }
        }
    }
    bool alz_x = true, alz_y = true;
    for (auto x : X) {
        if (x != 0) alz_x = false;
    }
    for (auto y : Y) {
        if (y != 0) alz_y = false;
    }
    bool isX = false, isY = false;
    dp[0][8100] = 1;
    if (!X.empty() && !alz_x) {
        if (s[0] == 'F')
            dp[1][8100 + X[0]] = 1;
        else
            dp[1][8100 - X[0]] = 1, dp[1][8100 + X[0]] = 1;

        for (int i = 2; i <= X.size(); i++) {
            for (int d = 0; d <= 16100; d++) {
                if (dp[i - 1][d] == 1) {
                    if (d - X[i - 1] >= 0) dp[i][d - X[i - 1]] = 1;
                    if (d + X[i - 1] <= 16100) dp[i][d + X[i - 1]] = 1;
                }
            }
        }
    } else if (alz_x) {
        dp[X.size()][8100] = 1;
    }
    if (dp[X.size()][x + 8100]) isX = true;
    memset(dp, sizeof(dp), 0);
    dp[0][8100] = 1;
    if (!Y.empty() && !alz_y) {
        dp[1][8100 - Y[0]] = 1, dp[1][8100 + Y[0]] = 1;
        for (int i = 2; i <= Y.size(); i++) {
            for (int d = 0; d <= 16100; d++) {
                if (dp[i - 1][d] == 1) {
                    if (d - Y[i - 1] >= 0) dp[i][d - Y[i - 1]] = 1;
                    if (d + Y[i - 1] <= 16100) dp[i][d + Y[i - 1]] = 1;
                }
            }
        }
    } else {
        dp[Y.size()][8100] = 1;
    }
    if (dp[Y.size()][y + 8100] == 1) isY = true;
    if (isX && isY) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}