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
int N, D, A;
vc<int> X, H;
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> N >> D >> A;
    vc<pi> mon(N);
    X.resize(N);
    H.resize(N);
    rep(i, N) { cin >> mon[i].first >> mon[i].second; }
    sort(ALL(mon));
    rep(i, N) {
        X[i] = mon[i].first;
        H[i] = mon[i].second;
    }
    vc<int> ids(N);
    rep(i, N) ids[i] = i;
    vc<int> S(N + 1, 0);
    int res = 0;
    rep(i, N) {
        if (S[i] < H[i]) {
            int need = (H[i] - S[i] + A - 1) / A;
            int right = X[i] + 2 * D;
            int id = upper_bound(ALL(X), right) - X.begin();
            S[i] += need * A;
            S[id] -= need * A;
            res += need;
        }
        S[i + 1] += S[i];
    }
    cout << res << endl;
}