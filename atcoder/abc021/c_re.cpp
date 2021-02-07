#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int mod = 1000000007;
int n, m, a, b;
vector<vector<int>> G(110);
int minc[110], check[110], dp[110];
void bfs() {
    queue<pair<int, int>> que;
    que.push(make_pair(0, a));
    for (int i = 0; i < 110; i++) minc[i] = 117117;
    while (!que.empty()) {
        auto cost = que.front().first;
        int v = que.front().second;
        que.pop();
        if (minc[v] <= cost) continue;
        minc[v] = cost;
        for (auto u : G[v]) {
            que.push(make_pair(cost + 1, u));
        }
    }
}
int calc() {
    for (int i = 0; i < 110; i++) check[i] = 0, dp[i] = 0;
    dp[a] = 1;
    queue<pair<int, int>> que;
    que.push(make_pair(0, a));
    while (!que.empty()) {
        int cost = que.front().first;
        int v = que.front().second;
        que.pop();
        if (check[v]) continue;
        check[v] = 1;
        for (auto u : G[v]) {
            if (minc[u] == cost + 1) {
                dp[u] += dp[v];
                dp[u] %= mod;
                que.push(make_pair(cost + 1, u));
            }
        }
    }
    return (dp[b] + mod) % mod;
}
int main() {
    cin >> n;
    cin >> a >> b;
    a--, b--;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    bfs();
    int res = calc();
    cout << res << endl;
    return 0;
}