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
    int n, k;
    cin >> n >> k;
    vc<int> p(n);
    vc<int> c(n);
    rep(i, n) {
        cin >> p[i];
        p[i]--;
    }
    rep(i, n) cin >> c[i];
    const int inf = 1LL << 60;
    vc<vc<int>> roop;
    for (int i = 0; i < n; i++) {
        vc<int> tmp;
        int score = 0;
        int now = i;
        vc<int> check(n, 0);
        now = p[now];
        while (check[now] == 0) {
            score += c[now];
            tmp.push_back(score);
            check[now] = 1;
            now = p[now];
        }
        roop.emplace_back(tmp);
    }
    int sc = -inf;
    for (int i = 0; i < n; i++) {
        auto cur = roop[i];
        int l = cur.size();
        int res = -inf;
        if (k <= l) {
            // non-roop
            for (int j = 0; j < min(k, l); j++) {
                chmax(res, cur[j]);
            }
        } else {
            // minus roop?
            if (cur.back() <= 0) {
                for (int j = 0; j < l; j++) {
                    chmax(res, cur[j]);
                }
            } else {
                int ind = 0;
                int now = -inf;
                for (int j = 0; j < l; j++) {
                    if (now < cur[j]) {
                        // 1周犠牲にしてmaxになるパターンがある
                        now = cur[j];
                        int last = cur.back();
                        int rop = (k - j - 1) / l;
                        chmax(res, rop * last + now);
                    }
                }
            }
        }
        chmax(sc, res);
    }
    cout << sc << endl;
}