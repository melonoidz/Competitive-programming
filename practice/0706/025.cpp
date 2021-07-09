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
int n, b, ans = 0;
void dfs(int pos, int last, string str) {
    if (pos == 0) {
        int rem = 1;
        rep(i, str.size()) { rem *= (str[i] - '0'); }
        int goal = rem + b;
        if (goal <= n) {
            //判定
            auto goal_str = to_string(goal);
            sort(ALL(goal_str), greater<char>());
            if (goal_str == str) {
                ans++;
            }
        }
        return;
    }
    for (int i = last; i > 0; i--) {
        auto str2 = str;
        str2 += ('0' + i);
        dfs(pos - 1, i, str2);
    }
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> n >> b;
    for (int i = 1; i <= 11; i++) {
        dfs(i, 9, "");
    }
    // Check
    string v = to_string(b);
    bool f = false;
    rep(i, v.size()) {
        if (v[i] == '0') f = true;
    }
    if (f && n >= b) ans++;
    cout << ans << endl;
}