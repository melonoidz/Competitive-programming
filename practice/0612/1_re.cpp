#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define Pr pair<ll, ll>
#define Tp tuple<ll, ll, ll>
using Graph = vector<vector<Tp>>;

ll mod = 998244353;

int main() {
    ll N, M;
    cin >> N >> M;
    Graph G(N + 1);
    rep(i, M) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        G[a].push_back(make_tuple(b, c, d));
        G[b].push_back(make_tuple(a, c, d));
    }
    // cout << "---" << endl;
    // Dijkstra (普通のダイクストラ)
    priority_queue<Pr, vector<Pr>, greater<Pr>> go;
    ll x, y, a, t;
    ll inf = 2e18;
    ll dist[N + 1];  //始点からの距離
    rep(j, N + 1) { dist[j] = inf; }
    go.push(make_pair(0, 1));
    dist[1] = 0;  //始点座標:s
    Pr p;
    while (!go.empty()) {
        p = go.top();
        go.pop();
        x = p.first;
        y = p.second;
        if (x > dist[y]) continue;
        for (auto q : G[y]) {  // G[y]:Graph
            // cout << y << endl;
            auto [a, c, d] = q;
            ll t = dist[y];
            ll k = sqrt((double)d);
            ll x = 2e18;
            rep(i, 3) {
                ll s = k - 2 + i;
                if (s < 0 || s < t) continue;
                x = min(x, c + (s - t) + d / (s + 1));
            }
            x = min(x, c + d / (t + 1));
            if (x + t < dist[a]) {
                dist[a] = x + t;
                go.push(make_pair(x + t, a));
            }
        }
    }
    if (dist[N] == inf) {
        cout << -1 << endl;
        return 0;
    }
    cout << dist[N] << endl;
}