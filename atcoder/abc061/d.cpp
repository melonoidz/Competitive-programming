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
const int INF = 1LL << 60;
using Edge = pair<int, int>;
int n, m;
vc<vc<Edge>> G;
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> n >> m;
    G.resize(n);
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        G[a].push_back(Edge(b, -c));
    }
    vc<int> dist(n, INF);
    bool negative = false;
    //正の閉路がある場合はinfになる
    //負のコストがあるのでベルマンフォード
    //ベルマンフォードは負の閉路を検出できる
    dist[0] = 0;
    for (int iter = 0; iter <= n * 2; iter++) {
        for (int v = 0; v < n; v++) {
            if (dist[v] >= INF / 2) continue;
            for (auto e : G[v]) {
                if (dist[e.first] > dist[v] + e.second) {
                    chmin(dist[e.first], dist[v] + e.second);
                    //2回目の結果が異なるとき無限に変えられる
                    if (e.first == n - 1 && iter == n * 2) negative = true;
                }
            }
        }
    }
    if (!negative)
        cout << -dist[n - 1] << endl;
    else
        cout << "inf" << endl;
    return 0;
}
