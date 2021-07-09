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
    vc<int> e(n);
    rep(i, n) cin >> e[i];
    int sum = accumulate(ALL(e), 0LL);
    if (sum % 3 != 0) {
        cout << "No" << endl;
        return 0;
    }
    vc<int> powt(13);
    powt[0] = 1;
    for (int i = 0; i < 12; i++) {
        powt[i + 1] = powt[i] * 3;
    }
    for (int mask = 0; mask < powt[n]; mask++) {
        int tmp = mask;
        vc<int> cur(3, 0);
        for (int p = 1; p <= n; p++) {
            int now = tmp % 3;
            cur[now] += e[p - 1];
            tmp /= 3;
        }
        if (cur[0] == cur[1] && cur[1] == cur[2]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}