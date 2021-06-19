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
bool is_prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}
bool jud(int l, int r) {
    auto f = __gcd(l, r);
    if (f != 1 && l != f && r != f) {
        return true;
    }
    return false;
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int l, r;
    cin >> l >> r;
    // rまでの周期を足す
    // l=primeならだめ
    int ans = 0;
    for (int x = l; x <= r; x++) {
        if (is_prime(x)) continue;
        int cur = 0;
        for (int j = 2; j * 2 <= x; j++) {
            if (is_prime(j) && x % j == 0) {
            }
        }
    }
    cout << ans * 2 << endl;
}