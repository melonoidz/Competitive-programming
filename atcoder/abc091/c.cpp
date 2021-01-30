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
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vc<pi> red;
    vc<pi> blue;
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        red.emplace_back(a, b);
    }
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        blue.emplace_back(a, b);
    }
    int cnt = 0;
    sort(red.begin(), red.end(), greater<pi>());
    sort(blue.begin(), blue.end());
    for (auto r : red) {
        bool flag = true;
        for (auto& b : blue) {
            if (flag) {
                if (r.first < b.first && r.second < b.second) {
                    cnt++;
                    // cout<<r.first<<" "<<r.second<<" "<<b.first<<"
                    // "<<b.second<<endl;
                    b.first -= 1e10;
                    b.second -= 1e10;
                    flag = false;
                }
            } else
                continue;
        }
    }
    cout << cnt << endl;
}