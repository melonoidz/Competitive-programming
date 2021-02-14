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

int N;
int deg[440000];
atcoder::dsu uf(430000);
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> N;
    rep(i, N) {
        int a, b;
        cin >> a >> b;
        uf.merge(a, b);
        deg[a]++;
        deg[b]++;
    }
    int ans = 0;
    // 握手の定理：次数は辺の本数の2倍になる
    for (auto g : uf.groups()) {
        int e = 0;
        for (auto no : g) {
            if(deg[no]!=0)cout << "Node= " << no <<endl;
            e += deg[no];
        }
        int v = g.size();
        ans += min(v, e / 2);
    }
    cout << ans << endl;
    return 0;
}