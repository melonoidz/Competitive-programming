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
    vc<int> cnt(10, 0);
    rep(i, a) {
        int n;
        cin >> n;
        if (n == 0) {
            cnt[9] = 1;
        } else {
            n--;
            cnt[n] = 1;
        }
    }
    rep(i, b) {
        int n;
        cin >> n;
        if (n == 0) {
            cnt[9] = 2;
        } else {
            n--;
            cnt[n] = 2;
        }
    }
    vc<string> ot(10);
    rep(i, 10) {
        if (cnt[i] == 0) {
            ot[i] = "x";
        } else if (cnt[i] == 1) {
            ot[i] = ".";
        } else {
            ot[i] = "o";
        }
    }
    cout << ot[6] << " " << ot[7] << " " << ot[8] << " " << ot[9] << endl;
    cout << " " << ot[3] << " " << ot[4] << " " << ot[5] << " " << endl;
    cout << "  " << ot[1] << " " << ot[2] << "  " << endl;
    cout << "   " << ot[0] << "   " << endl;
}