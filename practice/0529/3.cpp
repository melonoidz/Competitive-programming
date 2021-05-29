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
    int t1, t2;
    cin >> t1 >> t2;
    int a1, a2, b1, b2;
    cin >> a1 >> a2;
    cin >> b1 >> b2;
    int p = (a1 - b1) * t1;
    int q = (a2 - b2) * t2;
    if (p + q == 0) {
        cout << "infinity" << endl;
        return 0;
    }
    if (p > 0) {
        if (p + q > 0) {
            cout << 0 << endl;
            return 0;
        } else {
            //だんだんと遠ざかる
            int r = p + q;
            int ans = p / -r;
            ans *= 2;
            if (p % -r != 0) {
                ans++;
            }
            cout << ans << endl;
            return 0;
        }
    } else {
        if (p + q < 0) {
            cout << 0 << endl;
            return 0;
        } else {
            //だんだんと遠ざかる
            int r = p + q;
            int ans = -p / r;
            ans *= 2;
            if (-p % r != 0) {
                ans++;
            }
            cout << ans << endl;
            return 0;
        }
    }
}