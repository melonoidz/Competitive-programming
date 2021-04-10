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
    map<int, int> in;
    int b, buy[8], tmp;
    rep(i, 6) cin >> tmp, in[tmp] = 1;
    cin >> b;
    rep(i, 6) cin >> buy[i];
    int r = 0, bonus = 0;
    rep(i, 6) {
        r += in[buy[i]];
        bonus += buy[i] == b;
    }
    if (r == 6)
        cout << 1 << endl;
    else if (r == 5 && bonus)
        cout << 2 << endl;
    else if (3 <= r)
        cout << 8 - r << endl;
    else
        cout << 0 << endl;
}