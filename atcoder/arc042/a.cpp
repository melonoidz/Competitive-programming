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
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    map<int, int> th;
    rep(i, N) { th[i + 1] = 0; }
    rep(i, M) {
        int a;
        cin >> a;
        th[a] = M - i;
    }
    vc<pi> nz;
    vc<int> zero;
    for (auto m : th) {
        if (m.second == 0) {
            zero.push_back(m.first);
        } else {
            nz.emplace_back(m.second, m.first);
        }
    }
    sort(nz.begin(), nz.end());
    sort(zero.begin(), zero.end());
    for (auto p : nz) {
        cout << p.second << endl;
    }
    for (auto z : zero) {
        cout << z << endl;
    }
    return 0;
}