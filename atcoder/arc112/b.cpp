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
// https://betrue12.hateblo.jp/entry/2021/02/18/221855
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int b, c;
    cin >> b >> c;
    if (c == 2) {
        cout << 3 << endl;
        return 0;
    }

    if (b <= 0) {
        if (c % 2 == 0) {
            cout << 1 + (-b + (c - 2) / 2) - (b - c / 2) << endl;
        } else {
            cout << 1 + (-b + c / 2) - (b - c / 2) << endl;
        }
    } else {
        if (c % 2 == 0) {
            cout << 1 + (b + (c - 2) / 2) - (-b + (c - 2) / 2) << endl;
        } else {
            cout << 1 + (b + (c - 1) / 2) - (-b - (c - 1) / 2) << endl;
        }
    }
}