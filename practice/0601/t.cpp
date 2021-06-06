#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
int s, p;
vector<int> memo(1010, 0);
void dfs(int s, int p) {
    for (int x = 1; x <= p; x++) {
        int now = s * (100 + x) / 100;
        if (memo[p - x] < now) {
            memo[p - x] = now;
            dfs(now, p - x);
        }
    }
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> s >> p;
    memo[p] = s;
    dfs(s, p);
    int ans = memo[0];
    cout << ans << endl;
}