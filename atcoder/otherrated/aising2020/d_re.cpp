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

int modpow(ll a, ll n, ll mod) {
    if (mod <= 0) return 0;
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

vc<int> res(200020, -1);
int calc(int a) {
    if (a == 0) return 0;
    if (a == 1) return 1;
    if (res[a] != -1) return res[a];
    int cnt = popcount(a);
    int rec = a % cnt;
    res[a] = calc(rec) + 1;
    return res[a];
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    string x;
    cin >> x;
    int p = 0;
    for (auto u : x) p += u - '0';
    for (int i = 0; i < 200020; i++) {
        res[i] = calc(i);
    }
    int a1 = 0, a2 = 0;
    // xにおけるmod(p-1),mod(p+1)の結果を求める
    for (int i = 0; i < n; i++) {
        if (x[i] == '1') {
            if (p == 1) {
                a1 = 0;
            } else {
                a1 = (a1 + modpow(2, n - i - 1, p - 1)) % (p - 1);
            }
            a2 = (a2 + modpow(2, n - i - 1, p + 1)) % (p + 1);
        }
    }
    for (int i = 0; i < n; i++) {
        if (x[i] == '1') {
            // mod(p-1)
            if (p == 1) {
                cout << 0 << endl;
            } else {
                int ans =
                    1 + calc((a1 - modpow(2, n - i - 1, p - 1) + (p - 1)) %
                             (p - 1));
                cout << ans << endl;
            }
        } else {
            int ans = 1 + calc((a2 + modpow(2, n - i - 1, p + 1)) % (p + 1));
            cout << ans << endl;
        }
    }
}