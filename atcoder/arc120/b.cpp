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
using mint = atcoder::modint998244353;
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int h, w;
    cin >> h >> w;
    vc<string> s;
    rep(i, h) {
        string g;
        cin >> g;
        s.push_back(g);
    }
    mint ans = 1;
    for (int ij = 0; ij <= h + w - 1 - 1; ij++) {
        int rcnt = 0, bcnt = 0, ocnt = 0;
        for (int i = 0; i < h; i++) {
            int j = ij - i;
            if (j < 0 || j >= w) continue;
            if (s[i][j] == 'R') rcnt++;
            if (s[i][j] == 'B') bcnt++;
            if (s[i][j] == '.') ocnt++;
        }
        if (rcnt > 0 && bcnt > 0) ans *= 0;
        if (rcnt > 0 || bcnt > 0)
            ans *= 1;
        else
            ans *= 2;
    }
    cout << ans.val() << endl;
}