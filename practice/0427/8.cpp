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

int N;
vc<double> X(1100), Y(1100), C(1100);
bool ok(double r) {
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++) {
            int dy = abs(Y[i] - Y[j]);
            if (dy > r / C[i] + r / C[j]) return false;
            int dx = abs(X[i] - X[j]);
            if (dx > r / C[i] + r / C[j]) return false;
        }
    return true;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i] >> C[i];
    }
    double low = 0, high = 1e9;
    for (int i = 0; i < 50; i++) {
        const double med = (low + high) / 2;
        if (ok(med))
            high = med;
        else
            low = med;
    }
    cout << high << endl;
}