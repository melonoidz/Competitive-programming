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
int digit_sum(int x) {
    int ans = 0;
    while (x > 0) {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int n, k;
    cin >> n >> k;
    const int mod = 100000;
    vc<int> nxt(mod);
    rep(i, mod) { nxt[i] = (i + digit_sum(i)) % mod; }
    vc<int> stamp(mod, -1);
    int pos = n, cnt = 0;
    while (stamp[pos] == -1) {
        stamp[pos] = cnt;
        pos = nxt[pos];
        cnt++;
    }
    int cycle = cnt - stamp[pos];
    if (k >= stamp[pos]) {
        //サイクル圧縮後
        k = (k - stamp[pos]) % cycle + stamp[pos];
    }
    int ans = -1;
    rep(i, mod) {
        if (stamp[i] == k) {
            ans = i;
        }
    }
    cout << ans << endl;
}