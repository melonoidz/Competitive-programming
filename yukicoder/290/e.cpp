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
int cnt = 0;
vc<vc<pi>> G;
int bfs(int w, int st = 0, int dist = 0) {
    vc<int> ch(100100, 1e9);
    ch[st] = dist;
    queue<pi> pq;
    pq.push(pi(st, dist));
    while (!pq.empty()) {
        auto p = pq.front();
        pq.pop();
        auto now = p.first;
        auto d = p.second;
        for (auto u : G[now]) {
            if (ch[u.first] > d + 1 && u.second >= w) {
                ch[u.first] = d + 1;
                pq.push(pi(u.first, d + 1));
            }
        }
    }
    return cnt = ch[n - 1];
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> n >> m;
    G.resize(n);
    rep(i, m) {
        int s, t, d;
        cin >> s >> t >> d;
        s--, t--;
        G[s].emplace_back(t, d);
        G[t].emplace_back(s, d);
    }
    int ng = 0LL;
    int ok = 1e9 + 1;
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (bfs(mid) == 1e9) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    cout << ng << " " << cnt << endl;
}