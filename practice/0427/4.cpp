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
    vc<vc<int>> ind(c + 1);
    rep(i, n) {
        cin >> a[i];
        ind[a[i]].push_back(i + 1);
    }
    int all = n * (n + 1) / 2;
    vc<int> mi(c);
    for (int i = 1; i <= c; i++) {
        auto index = ind[i];

        bool las = false;
        index.push_back(0);
        vc<int> now;
        for (int j = 0; j < index.size(); j++) {
          
        }

        for (int j = 0; j < index.size() - 1; j++) {
            if (index[j] + 1 == index[j + 1]) {
                mi[i - 1] +=
            }
            mi[i - 1] +=
                (index[j + 1] - index[j] - 1) * (index[j + 1] - index[j]) / 2;
        }
        cout << i << " " << mi[i - 1] << endl;
    }
    rep(i, n) { cout << all - mi[i] << endl; }
}