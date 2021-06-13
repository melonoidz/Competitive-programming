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
// mod function
long long mod(long long a, long long mod) { return (a % mod + mod) % mod; }

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

long long modinv(long long a, long long mod) {
    long long b = mod, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b, swap(a, b);
        u -= t * v, swap(u, v);
    }
    u %= mod;
    if (u < 0) u += mod;
    return u;
}

// binomial coefficient
struct BiCoef {
    // max size of n of nCr
    int n_;

    // pm = p^k, p is prime
    // mod pm
    long long p_, pm_;

    // i! = p^ord[i] * fact[i] (mod. m)
    vector<long long> ord_, fact_;

    // constructor
    BiCoef(int n) : n_(n), ord_(n), fact_(n) {}
    BiCoef(long long p, long long pm, int n)
        : n_(n), p_(p), pm_(pm), ord_(n), fact_(n) {
        init(p, pm);
    }
    void init(int n) {
        ord_.resize(n);
        fact_.resize(n);
    }
    void init(long long p, long long pm) {
        p_ = p, pm_ = pm;
        ord_[0] = ord_[1] = 0;
        fact_[0] = fact_[1] = 1;
        for (int i = 2; i < n_; i++) {
            long long add = 0;
            long long ni = i;
            while (ni % p == 0) ++add, ni /= p;
            ord_[i] = ord_[i - 1] + add;
            fact_[i] = fact_[ni - 1] * ni % pm;
        }
    }
    void init(long long p, long long pm, int n) {
        init(n);
        init(p, pm);
    }

    // nCr mod. pm
    long long com(long long n, long long r) {
        if (n < 0 || r < 0 || n < r) return 0;
        long long e = ord_[n] - ord_[r] - ord_[n - r];
        long long res =
            fact_[n] * modinv(fact_[r] * fact_[n - r] % pm_, pm_) % pm_;
        res = res * modpow(p_, e, pm_) % pm_;
        return res;
    }
};
// BiCoef bf(3, 3, N);
const string alp = "BWR";
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    string c;
    cin >> c;
    BiCoef bf(3, 3, n);
    int res = 0;
    rep(i, n) {
        int val = 0;
        if (c[i] == 'W')
            val = 1;
        else if (c[i] == 'R')
            val = 2;
        res += bf.com(n - 1, i) * val % 3;
    }
    res %= 3;
    res = (n % 2 == 0) ? (3 - res) % 3 : res;
    cout << alp[res] << endl;
}