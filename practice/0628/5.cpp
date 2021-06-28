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

using mint = atcoder::modint1000000007;
typedef mint Type;
typedef vector<vector<Type>> Matrix;
int GetRank(Matrix a) {
    int h = a.size(), w = a[0].size();
    int res = 0, now = 0;
    for (int i = 0; i < h; i++) {
        Type ma = 0;
        int pivot;
        for (int j = i; j < h; j++) {
            if (a[j][now].val() > ma.val()) {
                ma = a[j][now];
                pivot = j;
            }
        }
        if (ma.val() == 0) {
            now++;
            if (now == w) break;
            i--;
            continue;
        }
        if (pivot != i) {
            for (int j = 0; j < w; j++) {
                swap(a[i][j], a[pivot][j]);
            }
        }
        Type tmp = 1 / a[i][now].val();
        for (int j = 0; j < w; j++) a[i][j] *= tmp;
        for (int j = 0; j < h; j++) {
            if (i != j) {
                Type tmp2 = a[j][now];
                for (int k = 0; k < w; k++) {
                    a[j][k] -= a[i][k] * tmp2;
                }
            }
        }
        res++;
    }
    return res;
}
bool Inv(Matrix a, Matrix& inv) {
    assert(a.size() == a[0].size() && inv.size() == inv[0].size());
    int n = a.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inv[i][j] = (i == j ? 1 : 0);
        }
    }
    for (int i = 0; i < n; i++) {
        Type ma = 0;
        int pivot;
        for (int j = i; j < n; j++) {
            if (a[j][i].val() > ma.val()) {
                ma = a[j][i];
                pivot = j;
            }
        }
        if (ma.val() == 0) return false;
        if (pivot != i) {
            for (int j = 0; j < n; j++) {
                swap(a[i][j], a[pivot][j]);
                swap(inv[i][j], inv[pivot][j]);
            }
        }
        Type tmp = 1 / a[i][i].val();
        for (int j = 0; j < n; j++) {
            a[i][j] *= tmp;
            inv[i][j] *= tmp;
        }
        for (int j = 0; j < n; j++) {
            if (i != j) {
                Type tmp2 = a[j][i];
                for (int k = 0; k < n; k++) {
                    a[j][k] -= a[i][k] * tmp2;
                    inv[j][k] -= inv[i][k] * tmp2;
                }
            }
        }
    }
    return true;
}
Matrix Add(const Matrix& a, const Matrix& b, bool minus = false) {
    assert(a.size() == b.size() && a[0].size() == b[0].size());
    int h = a.size(), w = a[0].size();
    Matrix c(h, vector<Type>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            c[i][j] = a[i][j] + (minus ? -1 : 1) * b[i][j];
        }
    }
    return c;
}
Matrix Sub(const Matrix& a, const Matrix& b) { return Add(a, b, true); }
Matrix Mul(const Matrix& a, const Matrix& b) {
    assert(a[0].size() == b.size());
    Matrix c(a.size(), vector<Type>(b[0].size()));
    for (int i = 0; i < a.size(); i++) {
        for (int k = 0; k < b.size(); k++) {
            for (int j = 0; j < b[0].size(); j++) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]);
            }
        }
    }
    return c;
}
Matrix Pow(Matrix a, long long n) {
    assert(a.size() == a[0].size());
    Matrix b(a.size(), vector<Type>(a.size()));
    for (int i = 0; i < a.size(); i++) {
        b[i][i] = 1;
    }
    while (n > 0) {
        if (n & 1) b = Mul(b, a);
        a = Mul(a, a);
        n >>= 1;
    }
    return b;
}
void PrintMatrix(const Matrix& a) {
    int h = a.size(), w = a[0].size();
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << a[i][j].val() << ' ';
        }
        cout << endl;
    }
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    //行列累乗
    int n, b, k;
    cin >> n >> b >> k;
    vc<int> c(11);
    rep(i, k) cin >> c[i];
    Matrix A(b, vc<Type>(b, 0));
    rep(i, b) {
        rep(j, k) {
            int nex = (i * 10 + c[j]) % b;
            A[i][nex]++;
        }
    }
    auto Z = Pow(A, n);
    auto ans = Z[0][0];
    cout << ans.val() << endl;
}