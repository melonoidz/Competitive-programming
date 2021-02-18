#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
#define int ll
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
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

vc<int> div(int a) {
    vc<int> ans;
    for (int i = 1; i * i <= a; i++) {
        if (a % i == 0) {
            if (i * i != a) {
                ans.push_back(i);
                ans.push_back(a / i);
            } else {
                ans.push_back(i);
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int n, k;
    cin >> n >> k;
    vc<int> a(n);
    rep(i, n) cin >> a[i];
    int sum = accumulate(a.begin(), a.end(), 0LL);
    auto tmp = div(sum);
    int ans = 1;
    for (auto num : tmp) {
        vc<int> na(n);
        rep(i, n) { na[i] = a[i] % num; }
        sort(na.begin(), na.end());
        vc<int> lhs(n + 1, 0), rhs(n + 1, 0);
        for (int i = 0; i < n; i++) {
            lhs[i + 1] = lhs[i] + na[i];
        }
        reverse(na.begin(), na.end());
        for (int i = 0; i < n; i++) {
            rhs[i + 1] = rhs[i] + num - na[i];
        }
        reverse(na.begin(), na.end());
        bool ok = false;
        for (int i = 1; i <= n; i++) {
            if (lhs[i] == rhs[n - i] && lhs[i] <= k) {
                ok = true;
            }
        }
        if (ok) {
            ans = max(ans, num);
        }
    }
    cout << ans << endl;
}