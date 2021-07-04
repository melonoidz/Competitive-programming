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

char other(char a, char b) {
    char res;
    if (a == 'R') {
        if (b == 'G') {
            res = 'B';
        } else
            res = 'G';
    }
    if (a == 'G') {
        if (b == 'B') {
            res = 'R';
        } else
            res = 'B';
    }
    if (a == 'B') {
        if (b == 'G') {
            res = 'R';
        } else
            res = 'G';
    }
    return res;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    map<char, int> rgb;
    rgb['R'] = -1;
    rgb['G'] = 0;
    rgb['B'] = 1;
    vvc<int> f(n + 1, vc<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i] == t[j]) {
                f[i][j] = rgb[s[i]];
            } else {
                f[i][j] = -(rgb[s[i]] + rgb[t[j]]) % 3;
            }
        }
    }
    rep(i, 6) {
        rep(j, 6) { cout << f[i][j] << " "; }
        cout << endl;
    }
    int ans = 0;
    for (int k = -n + 1; k < n; k++) {
        bool same = true;
        for (int i = 1; i < n; i++) {
            if (i + k >= 1 && i + 1 + k < n) {
                if (f[i][i + k] != f[i + 1][i + 1 + k]) {
                    same = false;
                }
            }
        }
        if (same) {
            cout << k << " " << endl;
            ans++;
        }
    }
    cout << ans << endl;
}