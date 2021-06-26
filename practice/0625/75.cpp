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
vector<int> prime_factorize(long long N) {
    // 12=({2,2},{3,1})
    vector<int> res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        while (N % a == 0) {
            N /= a;
            res.push_back(a);
        }
    }
    if (N != 1) res.push_back(N);
    return res;
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    auto p = prime_factorize(n);
    rep(i, 21) {
        if ((1 << i) >= p.size()) {
            cout << i << endl;
            return 0;
        }
    }
}