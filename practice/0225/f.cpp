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
    int t;
    cin >> t;
    rep(i, t) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a < b) {
            cout << "No" << endl;
        }
        else if (d < b) {
            cout << "No" << endl;
        }
        else if (c + 1 >= b) {
            cout << "Yes" << endl;

        } else {
            // a>=b, d>=b, c<b-1
            // c+1~b-1 ではbをまかなえない
            // d*x in[c+1-a , b-1-a] ??
            // dp-bq+a はgcd(b,d)の倍数
            int g = __gcd(b, d);
            int m = (b - a % g + g - 1) / g * g + a % g - g;
            if (m > c)
                cout << "No" << endl;
            else
                cout << "Yes" << endl;
        }
    }
}