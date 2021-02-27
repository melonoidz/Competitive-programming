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
    string s;
    cin >> s;
    string t;
    for (auto y : s) {
        if (y != 'x') t += y;
    }
    for (int i = 0; i < t.size(); i++) {
        if (t[i] != t[t.size() - i - 1]) {
            cout << -1 << endl;
            return 0;
        }
    }
    deque<char> cur;
    rep(i, s.size()) { cur.push_back(s[i]); }
    int ans = 0;
    while (cur.size()) {
        if (cur.front() == cur.back()) {
            cur.pop_front();
            if (cur.size()) cur.pop_back();
        } else if (cur.front() == 'x' && cur.back() != 'x') {
            ans++;
            cur.pop_front();
        } else if (cur.front() != 'x' && cur.back() == 'x') {
            ans++;
            cur.pop_back();
        }
    }
    cout << ans << endl;
}