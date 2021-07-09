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
    int a, b;
    cin >> a >> b;
    vc<string> f;
    rep(k, 100) {
        string s = "";
        if (k < 50) {
            rep(i, 100) s += ".";
        } else {
            rep(i, 100) s += "#";
        }
        f.push_back(s);
    }
    int cnt = 0;
    for (int i = 0; i < 50; i += 2) {
        if (cnt == b - 1) break;
        for (int j = 0; j < 100; j += 2) {
            if (cnt == b - 1) break;
            f[i][j] = '#';
            cnt++;
        }
    }
    cnt = 0;
    for (int i = 51; i < 100; i += 2) {
        if (cnt == a - 1) break;
        for (int j = 0; j < 100; j += 2) {
            if (cnt == a - 1) break;
            f[i][j] = '.';
            cnt++;
        }
    }
    cout << 100 << " " << 100 << endl;
    for (int i = 0; i < 100; i++) {
        cout << f[i] << endl;
    }
}