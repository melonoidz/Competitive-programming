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
int fcnt = 0, scnt = 0;
vc<vc<int>> G;
vc<int> F;
vc<int> S;
void dfs(int v, int p, int cnt, vc<int>& ch) {
    ch[v] = cnt;
    for (auto u : G[v]) {
        if (u != p) {
            dfs(u, v, cnt + 1, ch);
        }
    }
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    // dfs4回でよさそう(1から,Nから,1から(min), Nからmin)
    cin >> N;
    G.resize(N);
    F.resize(N);
    S.resize(N);
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0, -1, 0, F);
    dfs(N - 1, N, 0, S);

    rep(i, N) {
        if (F[i] <= S[i])
            fcnt++;
        else
            scnt++;
    }

    if (fcnt > scnt)
        cout << "Fennec" << endl;
    else
        cout << "Snuke" << endl;
    return 0;
}