#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
#define int ll
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int n; cin >> n;
    set<int> cnt;
    rep(i, n) {
        int a; cin >> a;
        cnt.insert(a);
    }
    int ans = n, col = cnt.size();
    while (col < ans) {
        ans -= 2;
    }
    cout << ans << endl;
}