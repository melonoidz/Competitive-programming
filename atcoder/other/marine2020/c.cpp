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
    int n, k;
    cin >> n >> k;
    vc<int> a(n);
    rep(i, n) cin >> a[i];
    for (int i = 1; i <= k; i++) {
        vc<int> tmp(n);
        if (i == 1)
            tmp.assign(n, 1);
        else
            tmp = a;
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (cnt > 0) {
                tmp[j]++;
                cnt--;
            }
            cnt += a[j];
        }

        // rep(m, n) cout << tmp[m] << " ";

        cnt = 0;
        for (int j = n - 1; j >= 0; j--) {
            if (cnt > 0) {
                tmp[j]++;
                cnt--;
            }
            cnt += a[j];
        }
        cout << endl;
        // rep(m, n) cout << tmp[m] << " ";

        a = tmp;
        bool same = true;
        for (int j = 0; j < n - 1; j++) {
            if (a[j] != a[j + 1]) same = false;
        }
        cout << endl;
        if (same) break;
    }
    rep(i, n) cout << a[i] << " ";
    cout << endl;
}