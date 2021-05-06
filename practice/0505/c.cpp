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
    string t;
    cin >> t;
    int res = 10000000000;
    if (t == "1") {
        cout << 2 * res << endl;
        return 0;
    }
    if (t == "11" || t == "10") {
        cout << res << endl;
        return 0;
    }
    string now;
    rep(i, (n + 2) / 3 + 1) { now += "110"; }
    bool ok = false;
    int st = -1;
    for (int i = 0; i < 3; i++) {
        string rex = now.substr(i);
        bool con = true;
        for (int j = 0; j < n; j++) {
            if (rex[j] != t[j]) con = false;
        }
        if (con) st = i;
    }
    if (st == -1) {
        cout << 0 << endl;
        return 0;
    }
    // N個のブロックからいくつの110がとれるか？
    int num = ceil((long double)(st + n) / 3);
    cout << res - num + 1 << endl;
}
