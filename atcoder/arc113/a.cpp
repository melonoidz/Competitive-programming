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

vector<pair<long long, long long>> prime_factorize(long long N) {
    vector<pair<long long, long long>> res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0;
        while (N % a == 0) {
            ++ex;
            N /= a;
        }
        res.push_back({a, ex});
    }
    if (N != 1) res.push_back({N, 1});
    return res;
}

vc<int> div(int i) {
    vc<int> res;
    int st = 1;
    while (st * st <= i) {
        if (i % st == 0) {
            res.push_back(st);
            if (st * st != i) res.push_back(i / st);
        }
        st++;
    }
    return res;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int K;
    cin >> K;
    vc<int> cnt(200200);
    for (int i = 1; i <= K; i++) {
        auto res = prime_factorize(i);
        int cur = 1;
        for (auto r : res) {
            cur *= (r.second + 1);
        }
        cnt[i] = cur;
    }
    int ans = 0;
    for (int i = 1; i <= K; i++) {
        for (auto u : div(i)) {
            ans += cnt[i / u];
        }
    }
    cout << ans << endl;
}