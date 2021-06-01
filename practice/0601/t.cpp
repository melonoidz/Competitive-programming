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
/**
 * @brief Cumulative-Sum-2D(二次元累積和)
 * @docs docs/cumulative-sum-2d.md
 * add(x, y, z): 要素 (x,y)に値 z を加える.
 * build(): 累積和を構築する.
 * query(sx, sy, gx, gy): 左下 (sx,sy), 右上 (gx,gy) の矩形和を求める
 * (半開区間で与えることに注意すること. 具体的には列 gx と行 gy は含まない)
 */
template <class T> struct CumulativeSum2D {
    vector<vector<T>> data;

    CumulativeSum2D(int W, int H) : data(W + 1, vector<int>(H + 1, 0)) {}

    void add(int x, int y, T z) {
        ++x, ++y;
        if (x >= data.size() || y >= data[0].size()) return;
        data[x][y] += z;
    }

    void build() {
        for (int i = 1; i < data.size(); i++) {
            for (int j = 1; j < data[i].size(); j++) {
                data[i][j] +=
                    data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];
            }
        }
    }

    T query(int sx, int sy, int gx, int gy) const {
        return (data[gx][gy] - data[sx][gy] - data[gx][sy] + data[sx][sy]);
    }
};
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    CumulativeSum2D<int> imo(2,2);
}