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
    int h, w, n;
    int sr, sc;
    string s, t;
    cin >> h >> w >> n;
    cin >> sr >> sc;
    cin >> s >> t;
    reverse(ALL(s));
    reverse(ALL(t));
    //逆ステップを確認するとRangeが求まる
    pi X(1, w), Y(1, h);
    rep(i, n) {
        int l = X.first, r = X.second;
        // aoki
        if (i > 0) {
            if (t[i] == 'R') {
                l = max(1LL, l - 1);
            }
            if (t[i] == 'L') {
                r = min(r + 1, w);
            }
        }
        // takahashi
        if (s[i] == 'R') {
            r--;
        }
        if (s[i] == 'L') {
            l++;
        }
        if (l > r) {
            cout << "NO" << endl;
            return 0;
        }
        X.first = l;
        X.second = r;
    }
    //下がh
    rep(i, n) {
        int p = Y.first, q = Y.second;
        // aoki
        if (i > 0) {
            if (t[i] == 'U') {
                q = min(q + 1, h);
            }
            if (t[i] == 'D') {
                p = max(1LL, p - 1);
            }
        }
        // takahashi
        if (s[i] == 'U') {
            p++;
        }
        if (s[i] == 'D') {
            q--;
        }
        if (p > q) {
            cout << "NO" << endl;
            return 0;
        }
        Y.first = p;
        Y.second = q;
    }
    if (X.first <= sc && sc <= X.second && Y.first <= sr && sr <= Y.second)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}