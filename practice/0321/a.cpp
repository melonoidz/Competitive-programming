#include <bits/stdc++.h>
#include <atcoder/all>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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
bool is_prime(long long N) {
    if (N == 1) return false;
    for (long long i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    vc<bool> check(50, false);
    int n;
    cin >> n;
    vc<int> prime;
    for (int i = 1; i <= 50; i++) {
        if (is_prime(i)) {
            prime.push_back(i);
        }
    }
    vc<int> x(n);
    int ans = 1e18;
    rep(i, n) { cin >> x[i]; }
    int l = prime.size();
    for (int bit = 0; bit < (1 << l); bit++) {
        int tmp = 1;
        for (int i = 0; i < l; i++) {
            if (bit & (1 << i)) {
                tmp *= prime[i];
            }
        }
        bool ok = true;
        for (auto t : x) {
            if (__gcd(t, tmp) == 1) ok = false;
        }
        if (ok) {
            ans = min(ans, tmp);
        }
    }
    cout << ans << endl;
    return 0;
}