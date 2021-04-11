#include <bits/stdc++.h>
#include <atcoder/all>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
using ll = long long;
#define int ll
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int T;
    cin >> T;
    rep(i, T) {
        int x;
        cin >> x;
        if (x % 2 == 1) {
            cout << "Odd" << endl;
        } else if (x % 4 == 0) {
            cout << "Even" << endl;
        } else {
            cout << "Same" << endl;
        }
    }
}