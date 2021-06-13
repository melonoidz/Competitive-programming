#include <bits/stdc++.h>
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
    int t;
    cin >> t;
    rep(i, t) {
        int n;
        cin >> n;
        int ans = 0;
        string l = to_string(n);
        if (l.length() == 1) {
            cout << n << endl;
        } else {
            ans += 9 * (l.length() - 1);
            int h = 1;
            int num = 1;
            string s;
            while (s.length() < l.length()) {
                h *= 10;
                num += h;
                s = to_string(num);
            }
            for (int q = 1; q < 10; q++) {
                int cur = num * q;
                if (cur <= n) ans++;
            }
            cout << ans << endl;
        }
    }
}