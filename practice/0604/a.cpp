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
int n;
vvc<int> edge(200200), weight(200200);
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    using mint = atcoder::modint1000000007;
    cin >> n;
    // dist(i,j)=dist(k,j)^dist(k,i)=dist(k,j)^dist(k,i)^dist(x,i)^dist(x,i)
    // dist(i,j)=dist(x,i)^dist(x,j)
    // bit毎に考えてansが求まる.
    rep(i, n - 1) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edge[u].push_back(v);
        edge[v].push_back(u);
        weight[u].push_back(w);
        weight[v].push_back(w);
    }
    vc<int> dist(200200, -1);
    dist[0] = 0;
    queue<int> que;
    que.push(0);
    while (!que.empty()) {
        auto now = que.front();
        que.pop();
        rep(i, edge[now].size()) {
            int nxt = edge[now][i];
            int sum = dist[now] ^ weight[now][i];
            if (dist[nxt] == -1) {
                dist[nxt] = sum;
                que.push(nxt);
            }
        }
    }
    mint ans = 0;
    for (int i = 0; i < 60; i++) {
        int odd = 0;
        rep(j, n) {
            if (dist[j] & (1LL << i)) odd++;
        }
        ans += mint(odd) * mint(n - odd) * mint(1LL << i);
    }
    cout << ans.val() << endl;
}