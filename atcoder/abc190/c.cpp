#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
#define int ll
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
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
    int N, M;
    cin >> N >> M;
    vc<int> A(M), B(M);
    rep(i, M) {
        cin >> A[i] >> B[i];
        A[i]--, B[i]--;
    }
    int k;
    cin >> k;
    vc<vc<int>> ball(k, vc<int>(2));
    rep(i, k) {
        cin >> ball[i][0] >> ball[i][1];
        ball[i][0]--, ball[i][1]--;
    }
    int ans = 0;
    for (int bit = 0; bit < (1 << k); bit++) {
        vc<int> now(N, 0);
        for (int i = 0; i < k; i++) {
            if (bit & (1 << i)) {
                now[ball[i][1]]++;
            } else {
                now[ball[i][0]]++;
            }
        }
        int cnt = 0;
        rep(j, M) {
            if (now[A[j]] >= 1 && now[B[j]] >= 1) cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}