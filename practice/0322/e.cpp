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

// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 1000000007;
struct mint {
    int x;
    mint(int x = 0) : x((x % mod + mod) % mod) {}
    mint operator-() const { return mint(-x); }
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint a) const { return mint(*this) += a; }
    mint operator-(const mint a) const { return mint(*this) -= a; }
    mint operator*(const mint a) const { return mint(*this) *= a; }
    mint pow(int t) const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }
    // for prime mod
    mint inv() const { return pow(mod - 2); }
    mint& operator/=(const mint a) { return *this *= a.inv(); }
    mint operator/(const mint a) const { return mint(*this) /= a; }
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int h, w;
    cin >> h >> w;
    vc<string> s;
    int alcnt = 0;
    rep(i, h) {
        string g;
        cin >> g;
        s.push_back(g);
        for (auto q : g) {
            if (q == '.') alcnt++;
        }
    }
    mint ans = 0;
    vc<vc<int>> sl(2010, vc<int>(2010, 0)), sr(2010, vc<int>(2010, 0)),
        su(2010, vc<int>(2010, 0)), sd(2010, vc<int>(2010, 0));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '#') {
                sl[i][j + 1] = 0;
            } else {
                sl[i][j + 1] = sl[i][j] + 1;
            }
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][w - 1 - j] == '#') {
                sr[i][w - 1 - j] = 0;
            } else {
                sr[i][w - 1 - j] = sr[i][w - 1 - j + 1] + 1;
            }
        }
    }
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            if (s[j][i] == '#') {
                sd[j + 1][i] = 0;
            } else {
                sd[j + 1][i] = sd[j][i] + 1;
            }
        }
    }
    for (int i = 0; i < w; i++) {
        for (int j = h; j > 0; j--) {
            if (s[j - 1][i] == '#') {
                su[j - 1][i] = 0;
            } else {
                su[j - 1][i] = su[j][i] + 1;
            }
        }
    }
    // rep(i, h + 1) {
    //     rep(j, w + 1) { cout << sd[i][j] << " "; }
    //     cout << endl;
    // }
    // rep(i, h + 1) {
    //     rep(j, w + 1) { cout << su[i][j] << " "; }
    //     cout << endl;
    // }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '#') continue;
            int tmp = sl[i][j + 1] + sr[i][j] + sd[i + 1][j] + su[i][j] - 3;
            int cur = alcnt - tmp;
            // cout << i << "=i " << j << "=j " << tmp << "=tmp " << cur <<
            // endl;
            ans += (mint(2LL).pow(alcnt) - mint(2LL).pow(cur));
        }
    }
    cout << ans << endl;
}