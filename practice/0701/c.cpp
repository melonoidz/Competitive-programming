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
    vvc<int> c(3, vc<int>(3));
    rep(i, 3) rep(j, 3) cin >> c[i][j];
    int sum = c[0][0] + c[1][1] + c[2][2];
    for (int a1 = 0; a1 <= sum; a1++) {
        for (int a2 = 0; a2 <= sum; a2++) {
            for (int a3 = 0; a3 <= sum; a3++) {
                if (a1 + a2 + a3 > sum) continue;
                if (c[0][0] - a1 == c[1][0] - a2 &&
                    c[1][0] - a2 == c[2][0] - a3) {
                    int b1 = c[0][0] - a1;
                    if (c[0][1] - a1 == c[1][1] - a2 &&
                        c[1][1] - a2 == c[2][1] - a3) {
                        int b2 = c[0][1] - a1;
                        if (c[0][2] - a1 == c[1][2] - a2 &&
                            c[1][2] - a2 == c[2][2] - a3) {
                            int b3 = c[0][2] - a1;
                            if (a1 + a2 + a3 + b1 + b2 + b3 == sum) {
                                cout << "Yes" << endl;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "No" << endl;
}