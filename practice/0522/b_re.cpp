#include <iostream>
#include <vector>
using namespace std;
int N, M;
vector<int> G[20];
int col[20];
bool dfs(int u) {
    for (int v : G[u]) {
        if (col[v] == -1) {
            col[v] = 3 - col[u];
            if (!dfs(v)) return false;
        } else if (col[u] == col[v]) {
            return false;
        }
    }
    return true;
}
main() {
    cin >> N >> M;
    vector<pair<int, int> > E(M);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        E[i] = make_pair(a, b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    long ans = 0;
    for (int k = 0; k < 1 << N; k++) {
        for (int i = 0; i < N; i++) {
            col[i] = -1;
            if (k >> i & 1) col[i] = 0;
        }
        bool ok = true;
        for (pair<int, int> e : E)
            if (col[e.first] == 0 && col[e.second] == 0) {
                ok = false;
                break;
            }
        if (!ok) continue;
        int cnt = 0;
        for (int i = 0; i < N; i++)
            if (col[i] == -1) {
                col[i] = 1;
                if (!dfs(i)) {
                    ok = false;
                    break;
                }
                cnt++;
            }
        if (ok) ans += 1 << cnt;
    }
    cout << ans << endl;
}
