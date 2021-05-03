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
    int n, c;
    cin >> n >> c;
    vc<int> a(n);
    rep(i, n) cin >> a[i];
    int all = (n + 1) * n / 2;
    map<int, vc<int>> cnt;
    rep(i, n) { cnt[a[i]].push_back(i); }
    for (int x = 1; x < c + 1; x++) {
        cnt[x].push_back(-1);
        cnt[x].push_back(n);
    }
    for (int x = 1; x < c + 1; x++) {
        int ans = 0;
        sort(ALL(cnt[x]));
        for (int j = 0; j < cnt[x].size() - 1; j++) {
            ans += (cnt[x][j + 1] - cnt[x][j]) *
                   (cnt[x][j + 1] - cnt[x][j] - 1) / 2;
        }
        cout << all - ans << endl;
    }
}