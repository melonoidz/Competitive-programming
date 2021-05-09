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
vc<vc<int>> tr(200200);
vc<int> num(200200);
bool used[200100];
int ind = 1;
void dfs(int st, int p = -1) {
    used[st] = true;
    num[st] = ind;
    for (auto u : tr[st]) {
        if (!used[u]) dfs(u, st);
    }
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    //今回はi->f(i)に線を引いた時，
    // iから出るEdgeは高々1本なので，UFの連結成分と同じになる
    int n;
    cin >> n;
    atcoder::dsu uf(n);
    using mint = atcoder::modint998244353;
    rep(i, n) {
        int f;
        cin >> f;
        uf.merge(i, --f);
    }
    cout << (mint(2).pow(uf.groups().size()) - 1).val() << endl;
}