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
    int N;
    cin >> N;
    vc<pi> rec;
    rep(i, N) {
        int x, y;
        cin >> x >> y;
        rec.emplace_back(x, y);
    }
    int ans = 0;
    for (int i = 0; i < rec.size(); i++) {
        for (int j = i; j < rec.size(); j++) {
            for (int k = j; k < rec.size(); k++) {
                if (j == k || i == j || i == k) continue;
                int ax, ay, bx, by;
                ax = rec[k].first - rec[i].first;
                ay = rec[k].second - rec[i].second;
                bx = rec[j].first - rec[i].first;
                by = rec[j].second - rec[i].second;
                if ((ax * by - ay * bx) % 2 == 0 && (ax * by - ay * bx) != 0)
                    ans++;
            }
        }
    }
    cout << ans << endl;
}