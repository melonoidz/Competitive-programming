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
    int n, k;
    cin >> n >> k;
    vc<int> a(n);
    rep(i, n) { cin >> a[i]; }
    vc<int> asum;
    int msum = 0;
    for (int i = 0; i < n; i++) {
        int res = 0;
        for (int j = i; j < n; j++) {
            res += a[j];
            asum.push_back(res);
            msum = max(msum, res);
        }
    }

    vc<int> bitc(42, 0);
    for (auto s : asum) {
        int tmp = s;
        int cnt = 41L;
        while (tmp > 0L && cnt >= 0L) {
            if (tmp >= pow(2L, cnt)) {
                tmp -= pow(2L, cnt);
                bitc[cnt]++;
            }
            cnt--;
        }
    }
    int dig = 0L;
    for (int i = 0; i < 41; i++) {
        if (bitc[i] >= k) {
            dig = max(dig, i);
        }
    }
    int ans = 0;
    vc<int> S;
    S = asum;
    while (!S.empty() && dig >= 0) {
        vc<int> now;
        for (auto s : S) {
            if (s >= pow(2L, dig)) {
                now.push_back(s - pow(2L, dig));
            }
        }
        if (now.size() >= k) {
            ans += pow(2L, dig);
            S = now;
        }
        dig--;
    }
    cout << ans << endl;
}