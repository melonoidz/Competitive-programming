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
void dfs(vvc<int>& g, vc<int>& sz, vc<int>& f, const int v) {
    int sum = 0;
    vc<int> seq;
    for (const auto& w : g[v]) {
        dfs(g, sz, f, w);
        sz[v] += sz[w];
        if (sz[w] % 2 == 1) {
            //奇数の場合
            seq.push_back(-f[w]);
        } else {
            if (f[w] < 0) {
                //有利な場合
                f[v] -= -f[w];
            } else {
                sum += -f[w];
            }
        }
    }
    // seqは，ダメージが少ないほうからとっていく
    sort(ALL(seq), greater<int>());
    seq.push_back(sum);
    rep(i, seq.size()) {
        if (i % 2 == 1) {
            f[v] += seq[i];
        } else {
            f[v] -= seq[i];
        }
    }
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vc<int> a(n - 1);
    rep(i, n - 1) cin >> a[i];
    //偶数なら青木のターン　-1　else +1
    //偶期がひっくり返ることがある　最下層なら子が奇数個
    //部分木のサイズが偶数なら，動かした人がmax かつ
    //もう一度これを選択可能　有利
    // f[v]：vの部分木でこのゲームをしたときに、先手が獲得するコインの枚数と後手が獲得するコインの枚数の差
    vvc<int> g(n);
    rep(i, n - 1) {
        a[i]--;
        g[a[i]].push_back(i + 1);
    }
    vc<int> g_size(n, 1), f(n, 0);  // 0->1
    dfs(g, g_size, f, 0);
    cout << (n + f[0]) / 2 << endl;
}