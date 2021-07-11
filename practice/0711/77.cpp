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
int n, t;
int judge(int dx, int dy) {
    int ans = -1;
    if (dx == 0) {
        if (dy == t) {
            ans = 3;
        } else if (dy == -t) {
            ans = 7;
        }
    }
    if (dx == t) {
        if (dy == t) {
            ans = 2;
        } else if (dy == -t) {
            ans = 8;
        } else if (dy == 0) {
            ans = 1;
        }
    }
    if (dx == -t) {
        if (dy == t) {
            ans = 4;
        } else if (dy == -t) {
            ans = 6;
        } else if (dy == 0) {
            ans = 5;
        }
    }
    return ans;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> n >> t;
    vc<pi> a(n), b(n);
    rep(i, n) { cin >> a[i].first >> a[i].second; }
    rep(i, n) { cin >> b[i].first >> b[i].second; }
    vc<int> ind;
    rep(i, n) ind.push_back(i);
    do {
        bool f = true;
        vc<int> ans(n);
         for (int j = 0; j < n; j++) {
            int p = ind[j];
            auto other = b[p];
            int dx = other.first - a[j].first;
            int dy = other.second - a[j].second;
            if ((dx == 0 || abs(dx) == t) && (dy == 0 || abs(dy) == t)) {
            } else {
                f = false;
            }
        }
        if (f) {
            cout << "Yes" << endl;
            rep(i, n - 1) cout << ans[i] << " ";
            cout << ans[n - 1] << endl;
            return 0;
        }
    } while (next_permutation(ALL(ind)));
    cout << "No" << endl;
}