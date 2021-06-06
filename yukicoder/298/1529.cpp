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
vector<pair<long long, long long>> prime_factorize(long long N) {
    // 12=({2,2},{3,1})
    vector<pair<long long, long long>> res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0;  // 指数
        while (N % a == 0) {
            ++ex;
            N /= a;
        }
        res.push_back({a, ex});
    }
    if (N != 1) res.push_back({N, 1});
    return res;
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    using mint = atcoder::modint998244353;
    int n;
    cin >> n;
    //半分で済む
    //素数は？ mapで数える?
    map<int, int> cnt;
    for (int i = 1; i <= n; i++) {
        int r = n - i;
        if (r < i) break;
        auto p = prime_factorize(i);
        auto q = prime_factorize(r);
        for (const auto& u : p) {
            cnt[u.first] = max(cnt[u.first], u.second);
        }
        for (const auto& v : q) {
            cnt[v.first] = max(cnt[v.first], v.second);
        }
    }
    mint ans = 1;
    for (const auto& u : cnt) {
        mint tmp = u.first;
        ans *= tmp.pow(u.second);
    }
    cout << ans.val() << endl;
}