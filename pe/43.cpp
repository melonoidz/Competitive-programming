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
    int ans = 0;
    vc<int> d{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    do {
        int p = d[1] * 100 + d[2] * 10 + d[3];
        int q = d[2] * 100 + d[3] * 10 + d[4];
        int r = d[3] * 100 + d[4] * 10 + d[5];
        int s = d[4] * 100 + d[5] * 10 + d[6];
        int x = d[5] * 100 + d[6] * 10 + d[7];
        int y = d[6] * 100 + d[7] * 10 + d[8];
        int z = d[7] * 100 + d[8] * 10 + d[9];
        if (p % 2 == 0 && q % 3 == 0 && r % 5 == 0 && s % 7 == 0 &&
            x % 11 == 0 && y % 13 == 0 && z % 17 == 0) {
            string now;
            for (const auto& u : d) now += to_string(u);
            int num = stol(now);
            ans += num;
        }
    } while (next_permutation(ALL(d)));
    cout << ans << endl;
}