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
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> n;
    vc<int> a(n);
    rep(i, n) {
        cin >> a[i];
        a[i] %= 200;
    }
    vc<vc<int>> dp_list(200);
    bool dp[200];
    // memset(dp, sizeof(dp), false);
    rep(i, n) {
        rep(j, 200) {
            if (dp[j] == false) continue;
            bool ng = false;
            rep(k, dp_list[j].size()) {
                if (dp_list[j][k] == i + 1) ng = true;
            }
            if (ng) continue;
            if (dp[(j + a[i]) % 200] == true) {
                //すでにj+a[i]MOD200がTrueの場合，部分列を出力する
                // Yes
                cout << "Yes" << endl;
                int x = dp_list[(j + a[i]) % 200].size();
                cout << x << " ";
                rep(k, x) {
                    cout << dp_list[(j + a[i]) % 200][k]
                         << ((k == x - 1) ? "\n" : " ");
                }
                int y = dp_list[j].size() + 1;
                cout << y << " ";
                rep(k, y - 1) cout << dp_list[j][k] << " ";
                cout << i + 1 << endl;
                return 0;
            } else {
                dp[(j + a[i]) % 200] = true;
                rep(k, dp_list[j].size()) {
                    dp_list[(j + a[i]) % 200].push_back(dp_list[j][k]);
                }
                dp_list[(j + a[i]) % 200].push_back(i + 1);
            }
        }
        // dp[a[i]]がTrueの時，同一剰余が複数あることを意味する．
        if (dp[a[i]] == true) {
            cout << "Yes" << endl;
            int x = dp_list[a[i]].size();
            cout << x << " ";
            rep(j, x) {
                cout << dp_list[a[i]][j] << ((j == x - 1) ? "\n" : " ");
            }
            cout << 1 << " " << i + 1 << endl;
            return 0;
        } else {
            dp[a[i]] = true;
            dp_list[a[i]].push_back(i + 1);
        }
    }
    cout << "No" << endl;
    return 0;
}