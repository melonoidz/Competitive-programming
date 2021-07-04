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
    // grundy数　0なら後手必勝　!=0なら先手必勝
    // すべての場合についてgrundy数を出せばよい
    int n;
    cin >> n;
    vc<int> w(n + 1), b(n + 1);
    rep(i, n) cin >> w[i + 1];
    rep(i, n) cin >> b[i + 1];
    vvc<int> grundy(55, vc<int>(1555));
    // Init
    rep(i, 51) {
        rep(j, 1501) {
            vc<int> mex(1555, 0);
            if (i >= 1) {
                //終了時grundy=0なので，そこから1個手前をみる　i=積む青石
                mex[grundy[i - 1][j + i]] = 1;
            }
            if (j >= 2) {
                for (int k = 1; k <= (j / 2); k++) {
                    //同じく=0の場合
                    mex[grundy[i][j - k]] = 1;
                }
            }
            for (int k = 0; k < 1555; k++) {
                // mex=0の箇所を探す
                if (mex[k] == 0) {
                    grundy[i][j] = k;
                    break;
                }
            }
        }
    }
    int sumxor = 0;
    for (int i = 1; i <= n; i++) {
        sumxor ^= grundy[w[i]][b[i]];
    }
    cout << (sumxor != 0 ? "First" : "Second") << endl;
}