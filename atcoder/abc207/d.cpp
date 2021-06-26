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

typedef double Type;
typedef vector<vector<Type>> Matrix;
int GetRank(Matrix a) {
    int h = a.size(), w = a[0].size();
    int res = 0, now = 0;
    for (int i = 0; i < h; i++) {
        Type ma = 0.0;
        int pivot;
        for (int j = i; j < h; j++) {
            if (a[j][now] > ma) {
                ma = a[j][now];
                pivot = j;
            }
        }
        if (ma == 0.0) {
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
        Type tmp = 1.0 / a[i][now];
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
            inv[i][j] = (i == j ? 1.0 : 0.0);
        }
    }
    for (int i = 0; i < n; i++) {
        Type ma = 0.0;
        int pivot;
        for (int j = i; j < n; j++) {
            if (a[j][i] > ma) {
                ma = a[j][i];
                pivot = j;
            }
        }
        if (ma == 0.0) return false;
        if (pivot != i) {
            for (int j = 0; j < n; j++) {
                swap(a[i][j], a[pivot][j]);
                swap(inv[i][j], inv[pivot][j]);
            }
        }
        Type tmp = 1.0 / a[i][i];
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
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    double eps = 1e-14;
    vc<pair<double, double>> s, t;
    rep(i, n) {
        double a, b;
        cin >> a >> b;
        s.emplace_back(a, b);
    }
    rep(i, n) {
        double a, b;
        cin >> a >> b;
        t.emplace_back(a, b);
    }
    sort(ALL(s));
    sort(ALL(t));
    bool same = true;
    rep(i, n) {
        if (s[i] != t[i]) same = false;
    }
    if (same) {
        cout << "Yes" << endl;
        return 0;
    }
    vc<Matrix> tmp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (i == j || i == k || j == k) continue;
                Matrix A(3, vc<Type>(3));
                A[0][0] = s[i].first;
                A[1][0] = s[i].second;
                A[2][0] = 1.0;
                A[0][1] = s[j].first;
                A[1][1] = s[j].second;
                A[2][1] = 1.0;
                A[0][2] = s[k].first;
                A[1][2] = s[k].second;
                A[2][2] = 1.0;
                Matrix res(3, vc<Type>(3));
                auto y = Inv(A, res);
                if (y) {
                    tmp.push_back(res);
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (i == j || i == k || j == k) continue;
                Matrix A(3, vc<Type>(3));
                A[0][0] = t[i].first;
                A[1][0] = t[i].second;
                A[2][0] = 1.0;
                A[0][1] = t[j].first;
                A[1][1] = t[j].second;
                A[2][1] = 1.0;
                A[0][2] = t[k].first;
                A[1][2] = t[k].second;
                A[2][2] = 1.0;
                rep(u, tmp.size()) {
                    auto C = Mul(A, tmp[u]);
                    bool ok = true;
                    if (C[2][0] != 0 || C[2][1] != 0) ok = false;
                    if (abs(C[2][2] - 1.00) > eps) ok = false;
                    if (C[0][0] + C[1][1] > eps) ok = false;
                    if (C[0][1] + C[1][0] > eps) ok = false;
                    if (abs((C[0][1] * C[0][1] + C[0][0] * C[0][0]) - 1.0) >
                        eps) {
                        ok = false;
                    }
                    if (ok) {
                        // rep(UU, 3) {
                        //     rep(YY, 3) { cout << C[UU][YY] << " "; }
                        //     cout << endl;
                        // }
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "No" << endl;
}