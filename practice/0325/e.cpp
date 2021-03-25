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
int N, u, v;
vc<vc<int>> T(100100);

vc<int> G;
void dfs(int u, int t, vc<int>& check) {
    bool li = true;
    for (auto v : T[u]) {
        if (u == v) continue;
        if (check[v] == -1) {
            check[v] = t + 1;
            dfs(v, t + 1, check);
            li = false;
        }
    }
    if (li) {
        G.push_back(u);
    }
}

void dfs2(int u, int t, vc<int>& ck) {
    for (auto v : T[u]) {
        if (u == v) continue;
        if (ck[v] == -1) {
            ck[v] = t + 1;
            dfs2(v, t + 1, ck);
        }
    }
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> N >> u >> v;
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        T[a].push_back(b);
        T[b].push_back(a);
    }
    int turn = 1e9;
    vc<int> check(100100, -1);
    vc<int> check2(100100, -1);
    check[u] = 0;
    check2[v] = 0;
    dfs(u, check[u], check);
    dfs2(v, check2[v], check2);
    // rep(i, 10) cout << check[i] << " ";
    // cout << endl;
    // rep(i, 10) cout << check2[i] << " ";
    // cout << endl;

    for (auto g : G) {
        // cout << g << "##" << endl;
        if (check[g] < check2[g]) {
            int now = check2[g] + (check[g] - check2[g] + 2 - 1) / 2;
            turn = min(turn, now);
        }
    }
    cout << turn << endl;
}