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
    int n, m;
    cin >> n >> m;
    vc<int> disk(110);
    rep(i, 105) disk[i] = i;
    int tmp = 0;
    int out = 0;
    rep(i, m) {
        int a;
        cin >> a;
        out = disk[a];
        disk[a] = tmp;
        tmp = out;
        cout << endl;
        for (int j = 1; j <= n; j++) {
            cout << disk[j] << endl;
        }
        cout << tmp << " = tmp" << endl;
        cout << "--" << endl;
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << disk[i] << endl;
    // }
    return 0;
}