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
int n, m;
vc<int> G[1 << 18], H[1 << 18];
bool used[1 << 18];
vc<int> I;
int cnts = 0;
void dfs(int pos) {
    used[pos] = true;
    for (int i : G[pos]) {
        if (!used[i]) dfs(i);
    }
    I.push_back(pos);
}
void dfs2(int pos) {
    used[pos] = true;
    cnts++;
    for (int i : H[pos]) {
        if (!used[i]) dfs2(i);
    }
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    //閉路があれば良いですねぇ
    //強連結成分分解(SCC)をする
    // https://hkawabata.github.io/technical-note/note/Algorithm/graph/scc.html
    cin >> n >> m;
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        H[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) dfs(i);
    }
    int ans = 0;
    // rep(i, I.size()) cout << I[i] << " ";
    cout << endl;
    reverse(ALL(I));
    for (int i = 0; i < n; i++) {
        used[i] = false;
    }
    for (int i : I) {
        if (used[i]) continue;
        cnts = 0;
        dfs2(i);
        ans += cnts * (cnts - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}