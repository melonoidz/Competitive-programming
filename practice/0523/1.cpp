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

int k, n, m;
bool cal(int x, vc<int>& a) {
    int lsum = 0, rsum = 0;
    for (const auto& aa : a) {
        lsum += max((m * aa - x + n - 1) / n, 0LL);
        rsum += (x + m * aa) / n;
    }
    return (lsum <= m && m <= rsum);
}

vc<int> construct(int x, vc<int>& a) {
    vc<int> res(k);
    rep(i, k) { res[i] = max(0LL, (m * a[i] - x + n - 1) / n); }
    auto l_sum = accumulate(ALL(res), 0LL);
    rep(i, k) {
        int limit = (x + m * a[i]) / n;
        int range = min(m - l_sum, limit - res[i]);
        res[i] += range;
        l_sum += range;
    }
    return res;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    //左端に注意
    cin >> k >> n >> m;
    vc<int> a(k);
    rep(i, k) cin >> a[i];
    int ng = -1;
    int ok = n * m;
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        auto now = cal(mid, a);
        if (now) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    const auto& res = construct(ok, a);
    rep(i, res.size()) { cout << res[i] << " "; }
    cout << endl;
}