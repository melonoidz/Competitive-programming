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
    vc<int> A(n + 1, 0), B(n + 1, 0);
    rep(i, n) {
        int c, p;
        cin >> c >> p;
        c--;
        if (c == 0) {
            A[i + 1] = A[i] + p;
            B[i + 1] = B[i];
        } else {
            A[i + 1] = A[i];
            B[i + 1] = B[i] + p;
        }
    }
    int q;
    cin >> q;
    rep(i, q) {
        int l, r;
        cin >> l >> r;
        cout << A[r] - A[l - 1] << " " << B[r] - B[l - 1] << endl;
    }
}