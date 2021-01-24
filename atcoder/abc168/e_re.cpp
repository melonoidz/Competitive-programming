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

pair<int, int> rev(pair<int, int> x) {
    int a = -x.first;
    int b = x.second;
    if (a < 0) return make_pair(-b, -a);
    return make_pair(b, a);
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vc<int> a(n), b(n);
    int a_z = 0, b_z = 0, z_z = 0;
    map<pair<int, int>, int> cnt;
    rep(i, n) { cin >> a[i] >> b[i]; }
    rep(i, n) {
        if (a[i] == 0 && b[i] == 0)
            z_z++;
        else if (a[i] == 0)
            a_z++;
        else if (b[i] == 0)
            b_z++;
        else {
            int g = __gcd(abs(a[i]), abs(b[i]));
            a[i] /= g;
            b[i] /= g;
            if (b[i] < 0) {
                a[i] *= -1;
                b[i] *= -1;  //分母を正にする
            }
            cnt[make_pair(a[i], b[i])]++;
        }
    }
    mint ans = mint(2).pow(a_z) + mint(2).pow(b_z) - mint(1);
    set<pair<int, int>> used;
    for (const auto& cn : cnt) {
        if (!used.count(cn.first)) {
            auto p = cn.first;
            auto pp = rev(p);
            if (cnt.count(pp)) {
                ans *= mint(2).pow(cnt[p]) + mint(2).pow(cnt[pp]) - mint(1);
                used.insert(pp);
            } else {
                ans *= mint(2).pow(cnt[p]);
            }
        }
    }
    ans += z_z;
    ans -= mint(1);
    cout << ans << endl;
}