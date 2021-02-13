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
int N, M;
vc<vc<pi>> G(2100);
vc<vc<int>> goal(2100);
int bfs(int start) {
    queue<pi> que;
    vc<vc<int>> cost(2100, vc<int>(2100, 1e9));
    vc<bool> check(2100, false);
    check[start] = true;
    que.push(make_pair(start, 0));
    while (!que.empty()) {
        auto p = que.front();
        que.pop();
        int now = p.first;
        int time = p.second;
        for (auto np : G[now]) {
            int nx = np.first;
            int nc = np.second;
            if (!check[nx]) {
                check[nx] = true;
                if (nx != now) {
                    int ntime = time + nc;
                    if (cost[now][nx] > ntime) {
                        cost[now][nx] = ntime;
                        que.push(make_pair(nx, ntime));
                    }
                }
            }
        }
    }
    int res = 1e9;
    for (auto g : goal[start]) {
        for (auto ps : G[g]) {
            if (ps.first == start) {
                if (cost[start][g] != 1e9) {
                    int tmp = cost[start][g] + ps.second;
                    res = min(res, tmp);
                }
            }
        }
    }
    return res;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> N >> M;
    rep(i, M) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        bool is = false;
        for (auto v : G[a]) {
            if (v.first == b) {
                v.second = min(v.second, c);
                is = true;
            }
        }
        if (!is) G[a].push_back(make_pair(b, c));
        goal[b].push_back(a);
    }
    for (int i = 0; i < N; i++) {
        int ans = bfs(i);
        for (auto yu : G[i]) {
            if (yu.first == i) {
                ans = min(ans, yu.second);
            }
        }
        if (ans == 1e9) {
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }
    }
}