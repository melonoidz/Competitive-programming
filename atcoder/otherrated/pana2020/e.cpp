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

bool match(char ls, char rs) { return (ls == rs || ls == '?' || rs == '?'); }

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    string a, b, c;
    bool ab[100000], ac[100000], bc[100000];
    memset(ab, true, sizeof(ab));
    memset(ac, true, sizeof(ac));
    memset(bc, true, sizeof(bc));
    cin >> a >> b >> c;
    int al = a.length();
    int bl = b.length();
    int cl = c.length();

    rep(i, al) {
        rep(j, bl) {
            if (!match(a[i], b[j])) {
                ab[i - j + 10000] = false;
            }
        }
    }
    rep(i, al) {
        rep(j, cl) {
            if (!match(a[i], c[j])) {
                ac[i - j + 10000] = false;
            }
        }
    }
    rep(i, bl) {
        rep(j, cl) {
            if (!match(b[i], c[j])) {
                bc[i - j + 10000] = false;
            }
        }
    }

    int ans = 3 * 2000;
    for (int i = -2 * 2000; i <= 2 * 2000; i++) {
        for (int j = -2 * 2000; j <= 2 * 2000; j++) {
            if (ab[i + 10000] && ac[j + 10000] && bc[j - i + 10000]) {
                int L = min(0LL, min(i, j));
                int R = max(al, max(bl + i, cl + j));
                ans = min(ans, R - L);
            }
        }
    }
    cout << ans << endl;
    return 0;
}