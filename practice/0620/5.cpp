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
    int n, m;
    cin >> n >> m;
    vc<int> x(m), y(m), z(m);
    rep(i, m) { cin >> x[i] >> y[i] >> z[i]; }
    vc<int> dp((1 << n) + 5);
    dp[0] = 1;
    rep(i, n) {
        // https://note.com/momomo0214/n/n290943bce6ec
        for (int bit = 0; bit < (1 << n); bit++) {
            int bit_num = 0;
            //桁数確認
            rep(k, n) {
                if (bit & (1 << k)) bit_num++;
            }
            if (bit_num != i) continue;
            rep(add, n) {
                bool ok = true;
                //すでに入っていたらcontinue
                if (bit & (1 << add)) continue;
                //遷移後を仮定する
                int next_bit = bit | (1 << add);
                rep(mi, m) {
                    //数字追加後がxじゃないとパス
                    if (i + 1 != x[mi]) continue;
                    int bit_num_y = 0;
                    rep(k, y[mi]) {
                        if (next_bit & (1 << k)) bit_num_y++;
                    }
                    if (bit_num_y > z[mi]) ok = false;
                }
                if (ok) dp[next_bit] += dp[bit];
            }
        }
    }
    cout << dp[(1 << n) - 1] << endl;
    return 0;
}