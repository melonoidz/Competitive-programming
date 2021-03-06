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
    int p, q, r, k;
    cin >> p >> q >> r >> k;
    vc<int> a(1500), dig(1010, 0);
    a[1] = p % 10;
    a[2] = q % 10;
    a[3] = r % 10;
    int timestamp = 3;
    dig[a[1] * 1 + a[2] * 10 + a[3] * 100] = timestamp;
    int res = k;
    for (int i = 4; i <= k; i++) {
        a[i] = (a[i - 1] + a[i - 2] + a[i - 3]) % 10;
        int nex = a[i - 2] * 1 + a[i - 1] * 10 + a[i] * 100;
        if (dig[nex] != 0) {
            int cycle = i - dig[nex];
            res = (k - dig[nex]) % cycle + dig[nex];
            break;
        }
        dig[nex] = i;
    }
    cout << a[res] << endl;
    return 0;
}