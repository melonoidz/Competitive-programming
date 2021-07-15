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
    int n;
    cin >> n;
    vc<int> p(n), q(n);
    rep(i, n) cin >> p[i];
    rep(i, n) cin >> q[i];
    vc<string> cur;
    vc<int> u;
    rep(i, n) u.push_back(i + 1);
    do {
        string tmp;
        for (int j = 0; j < n; j++) {
            auto x = to_string(u[j]);
            tmp += x;
        }
        cur.push_back(tmp);

    } while (next_permutation(ALL(u)));
    sort(ALL(cur));
    int aa = 0, bb = 0;
    for (int i = 0; i < cur.size(); i++) {
        bool a = true, b = true;
        rep(j, n) {
            if (p[j] != (cur[i][j] - '0')) a = false;
            if (q[j] != (cur[i][j] - '0')) b = false;
        }
        if (a) aa = i;
        if (b) bb = i;
    }
    cout << abs(aa - bb) << endl;
}