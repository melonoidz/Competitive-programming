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
int check(int x, vector<int> _v) {
    vector<int> v;
    for (auto i : _v)
        if (i) v.push_back(i);
    int n = v.size();
    int cent = 8080;
    set<int> dp;
    dp.insert(0);
    for (auto i : _v) {
        set<int> pd;
        for (auto j : dp) {
            pd.insert(j + i);
            pd.insert(j - i);
        }
        swap(dp, pd);
    }

    for (auto i : dp)
        if (i == x) return 1;
    return 0;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    string s;
    cin >> s;
    int xy[2];
    cin >> xy[0] >> xy[1];
    int n = s.length();
    int pre = -1, state = 0;
    vc<int> v[2];
    rep(i, n) {
        if (s[i] == 'T') {
            v[state].push_back(i - pre - 1);
            state = 1 - state;
            pre = i;
        }
    }
    v[state].push_back(n - pre - 1);
    xy[0] -= v[0].front();
    v[0].erase(v[0].begin(), v[0].begin() + 1);
    rep(d, 2) {
        if (!check(xy[d], v[d])) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}