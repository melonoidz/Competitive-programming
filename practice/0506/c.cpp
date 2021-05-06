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
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vc<vc<int>> a(n, vc<int>(n));
    vc<int> num;
    rep(i, n) {
        num.push_back(i);
        rep(j, n) { cin >> a[i][j]; }
    }
    int m;
    cin >> m;
    vc<pi> bad;
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        bad.emplace_back(x, y);
    }
    const int inf = 1LL << 60;
    int ans = inf;
    do {
        int time = 0;
        bool ok = true;
        rep(i, n - 1) {
            rep(j, m) {
                if ((num[i] == bad[j].first && num[i + 1] == bad[j].second) ||
                    (num[i] == bad[j].second && num[i + 1] == bad[j].first))
                    ok = false;
            }
        }
        if (ok) {
            rep(i, n) time += a[num[i]][i];
            chmin(ans, time);
        }

    } while (next_permutation(ALL(num)));
    if (ans == inf) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}