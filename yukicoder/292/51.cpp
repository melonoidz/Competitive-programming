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
bool isprime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    // 1,3,5,7,9
    int prime = 0;
    int all = 1;
    for (int i = 3;; i += 2) {
        int dr = i * i;
        int dl = dr - i + 1;
        int ul = dl - i + 1;
        int ur = ul - i + 1;
        all += 4;
        if (isprime(dr)) prime++;
        if (isprime(dl)) prime++;
        if (isprime(ur)) prime++;
        if (isprime(ul)) prime++;
        cout << prime << " " << all << endl;
        auto now = (100.0 * prime / all);
        cout << now << endl;
        if (now < 10) {
            cout << i << endl;
            return 0;
        }
    }
}