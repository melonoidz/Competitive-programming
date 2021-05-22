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
        if (x % i == 0) return false;
    }
    return true;
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int goal = 1000000;
    // int goal = 1000;
    vc<int> p;
    for (int i = 2; i <= goal; i++) {
        if (is_prime(i)) p.push_back(i);
    }
    vc<int> sump(p.size() + 1);
    sump[0] = 0;
    for (int i = 0; i < p.size(); i++) {
        sump[i + 1] = sump[i] + p[i];
    }
    int ans = 0;
    int tmpl = 0;
    // rep(i, 15) cout << p[i] << endl;
    for (int i = 0; i < sump.size(); i++) {
        for (int j = 0; j < i; j++) {
            int now = sump[i] - sump[j];
            if (is_prime(now) && now > ans && now < goal && tmpl < i - j) {
                // cout << i << " " << j << " " << now << endl;
                ans = now;
                chmax(tmpl, i - j);
            }
        }
    }
    cout << ans << endl;
}