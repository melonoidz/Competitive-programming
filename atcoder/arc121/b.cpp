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
    vc<vc<int>> dog(3);  // R,G,B
    rep(i, 2 * n) {
        int a;
        cin >> a;
        char c;
        cin >> c;
        if (c == 'R') {
            dog[0].push_back(a);
        } else if (c == 'G') {
            dog[1].push_back(a);
        } else {
            dog[2].push_back(a);
        }
    }
    vc<int> remain;
    rep(i, 3) {
        sort(ALL(dog[i]), greater<int>());
        if (dog[i].size() % 2 != 0) {
            // 1dog->max or min
            remain.push_back(i);
        }
    }
    if (remain.size() == 0) {
        cout << 0 << endl;
        return 0;
    } else {
        int res = 1e18;
        int an = remain.front();
        int bn = remain.back();
        auto a = dog[an];
        auto b = dog[bn];
        // b.push_back(0);
        b.push_back(res);
        sort(ALL(a));
        sort(ALL(b));
        for (int i = 0; i < a.size(); i++) {
            auto ld = lower_bound(ALL(b), a[i]) - b.begin();
            int ll = b[ld], lr = b[max(0LL, ld - 1LL)];
            auto rd = upper_bound(ALL(b), a[i]) - b.begin();
            auto pr = b[rd], rl = b[max(0LL, rd - 1LL)];
            res = min({res, abs(ll - a[i]), abs(lr - a[i]), abs(pr - a[i]),
                       abs(rl - a[i])});
        }
        cout << res << endl;
    }
}