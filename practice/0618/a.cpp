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
    int n, k, d;
    cin >> n >> k >> d;
    vc<int> a(n);
    rep(i, n) cin >> a[i];
    // k-i個選択するときには(k-i)*d個は必ず必要
    // n, n-d, n-2d, n-3d, n-(k-1)d
    priority_queue<pi, vc<pi>, greater<pi>> pq;
    int l = 0, r = n - (k - 1) * d;
    rep(i, r) { pq.push(pi(a[i], i)); }
    if (pq.empty()) {
        cout << -1 << endl;
        return 0;
    }
    queue<int> ans;
    rep(i, k) {
        while (1) {
            auto p = pq.top();
            pq.pop();
            if (l <= p.second) {
                ans.push(p.first);
                if (r == n) break;
                for (int j = r; j < r + d; j++) {
                    pq.push(pi(a[j], j));
                }
                l = p.second + d;
                r += d;
                break;
            }
        }
    }
    rep(i, k) {
        auto u = ans.front();
        ans.pop();
        cout << u << " ";
    }
    cout << endl;
    return 0;
}