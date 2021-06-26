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
    int n, m, k;
    cin >> n >> m >> k;
    vc<pi> task;
    rep(i, n) {
        int a, b;
        a--, b--;
        cin >> a >> b;
        task.emplace_back(a, b);
    }
    vc<vc<int>> ans;
    for (int i = 0; i < n; i++) {
        for (int bit = 0; bit < (1 << n); bit++) {
            int nowbit = 0;
            for (int j = 0; j < n; j++) {
                if (bit & (1 << j)) nowbit++;
            }
            if (nowbit != i) continue;
            for (int add = 0; add < n; add++) {
                if (bit & (1 << add)) continue;
                bool ok = true;
                int nxt = bit | (1 << add);
                for (int j = 0; j < m; j++) {
                    if (!(nxt & (1 << task[j].first)) ||
                        !(nxt & (1 << task[j].second)))
                        continue;
                    
                }
            }
        }
    }
}