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
int N, P, K;
vvc<int> A(42, vc<int>(42)), dist(42, vc<int>(42));
int count_n(int x) {
    rep(i, N) {
        rep(j, N) {
            if (A[i][j] == -1)
                dist[i][j] = x;
            else
                dist[i][j] = A[i][j];
        }
    }
    rep(k, N) {
        rep(i, N) {
            rep(j, N) { chmin(dist[i][j], dist[i][k] + dist[k][j]); }
        }
    }
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (dist[i][j] <= P) cnt++;
        }
    }
    return cnt;
}

int get_b(int cnts) {
    int ng = 0;
    int ok = 1e18;
    while (abs(ng - ok) > 1) {
        int mid = (ok + ng) / 2LL;
        if (count_n(mid) <= cnts) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    return ok;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> N >> P >> K;
    rep(i, N) rep(j, N) cin >> A[i][j];
    auto l = get_b(K);
    auto r = get_b(K - 1);
    if (r - l >= 2000000000LL)
        cout << "Infinity" << endl;
    else
        cout << r - l << endl;
    return 0;
}