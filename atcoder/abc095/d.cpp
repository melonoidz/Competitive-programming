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
int N, C;
vc<pair<int, pi>> S;
// https://blog.hamayanhamayan.com/entry/2018/04/21/225805
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> N >> C;
    rep(i, N) {
        int x, v;
        cin >> x >> v;
        pair<int, pi> s;
        s.first = i;
        s.second = pi(x, v);
        S.push_back(s);
    }
    vc<pi> l, r;
    for (auto s : S) {
        if (s.first < N / 2) {
            l.push_back(s.second);
        } else {
            r.push_back(s.second);
        }
    }
    vc<int> sl(l.size() + 1), sr(r.size() + 1);
    for (int i = 0; i < l.size(); i++) {
        sl[i + 1] = sl[i] + l[i].second;
    }
    for (int i = 0; i < r.size(); i++) {
        sr[i + 1] = sr[i] + r[i].second;
    }
    vc<int> suml(l.size()), sumr(r.size());
    for (int i = 0; i < l.size(); i++) {
        suml[i] = sl[i + 1] - l[i].first;
    }
    for (int i = 0; i < r.size(); i++) {
        sumr[i] = sr[i + 1] - r[i].first;
    }

    int ans = 0LL;
    for (int i = 0; i < r.size() - 1; i++) {
        int cost =
            sr[i + 1] - 2 * r[i].first + *max_element(suml.begin(), suml.end());
        ans = max(ans, cost);
    }
    for (int i = 0; i < l.size() - 1; i++) {
        int cost =
            sl[i + 1] - 2 * l[i].first + *max_element(sumr.begin(), sumr.end());
        ans = max(ans, cost);
    }
    cout << max(0LL, ans) << "\n";
    return 0;
}