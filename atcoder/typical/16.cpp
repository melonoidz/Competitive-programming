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
    int n;
    cin >> n;
    int a, b, c;
    cin >> a >> b >> c;
    vc<int> coin = {a, b, c};
    sort(ALL(coin), greater<int>());
    int ans = 1LL << 60;
    for (int i = 0; i <= 1 + n / coin[0]; i++) {
        int tmp = n - i * coin[0];
        if (tmp == 0) {
            chmin(ans, i);
        } else {
            if (tmp > 0) {
                for (int j = 0; j <= 1 + tmp / coin[1]; j++) {
                    int nx = tmp - j * coin[1];
                    if (nx == 0) {
                        chmin(ans, i + j);
                    } else {
                        if (nx > 0) {
                            if (nx % coin[2] == 0) {
                                chmin(ans, i + j + nx / coin[2]);
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
}