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
    int n, q;
    cin >> n >> q;
    int odddiff = 0, evendiff = 0;
    map<int, int> oddcnt, evencnt;
    vc<int> diff(200100, 0), h(200100, 0);
    rep(i, n) cin >> h[i];
    rep(i, n - 1) diff[i] = h[i + 1] - h[i];
    rep(i, n - 1) {
        if (i % 2 == 0) {
            oddcnt[diff[i]]++;
        } else {
            evencnt[diff[i]]++;
        }
    }
    rep(i, q) {
        int t;
        cin >> t;
        if (t == 1) {
            int v;
            cin >> v;
            odddiff -= v;
            evendiff += v;
        } else if (t == 2) {
            int v;
            cin >> v;
            odddiff += v;
            evendiff -= v;
        } else {
            int u, v;
            cin >> u >> v;
            u--;
            if (u % 2 == 0) {
                if (u != 0) {
                    // cout << u << endl;
                    evencnt[diff[u - 1]]--;
                    diff[u - 1] += v;
                    evencnt[diff[u - 1]]++;
                }
                if (u < n - 1) {
                    oddcnt[diff[u]]--;
                    diff[u] -= v;
                    oddcnt[diff[u]]++;
                }
            } else {
                oddcnt[diff[u - 1]]--;
                diff[u - 1] += v;
                oddcnt[diff[u - 1]]++;
                if (u < n - 1) {
                    evencnt[diff[u]]--;
                    diff[u] -= v;
                    evencnt[diff[u]]++;
                }
            }
        }
        int ans = oddcnt[0 - odddiff] + evencnt[0 - evendiff];
        cout << ans << endl;
    }
}