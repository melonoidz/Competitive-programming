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
    int n, k;
    cin >> n >> k;
    //高速素因数分解
    const int MAX = 10000100;
    vc<int> sieve;
    rep(i, MAX) sieve.emplace_back(i);
    int p = 2;
    while (p * p <= MAX) {
        if (sieve[p] == p) {
            for (int i = 2 * p; i <= MAX; i += p) {
                if (sieve[i] == i) sieve[i] = p;
            }
        }
        p++;
    }
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        int num = i;
        set<int> rec;
        while (num > 1) {
            rec.insert(sieve[num]);
            num /= sieve[num];
        }
        if (rec.size() >= k) {
            ans++;
        }
    }
    cout << ans << endl;
}