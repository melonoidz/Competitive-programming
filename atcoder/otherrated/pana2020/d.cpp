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
int n;
string tmp = "a";
vc<string> ans;

void solve(int cnt, char mx, string now) {
    if (cnt == n) return;

    for (char i = 'a'; i <= mx + 1; i++) {
        if (cnt == n - 1) ans.push_back(now + i);
        solve(cnt + 1, max(mx, i), now + i);
    }
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> n;
    if (n == 1) {
        cout << "a" << endl;
        return 0;
    }
    solve(1, 'a', "a");
    rep(i, ans.size()) { cout << ans[i] << endl; }
}