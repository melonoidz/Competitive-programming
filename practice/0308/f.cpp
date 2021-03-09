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
struct edge {
    int from;
    int to;
    int cost;
    edge(int _from, int _to, int _cost) : from(_from), to(_to), cost(_cost){};
};
vc<edge> ans;

// make [add, add+l) のバイパス
void bypass(int add, int L) {
    if (L <= 0) return;
    for (int k = 19; k >= 0; k--) {
        if (L >= (1 << k)) {
            ans.push_back(edge(k + 1, 20, add));
            bypass(add + (1 << k), L - (1 << k));
            break;
        }
    }
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int L;
    cin >> L;
    for (int i = 1; i < 20; i++) {
        //~2^20
        ans.push_back(edge(i, i + 1, 0));
    }
    for (int k = 19; k >= 1; k--) {
        // 334=256+78 のように分ける
        // k本辺を張って[0,2^k)をつくる
        if (L >= (1 << k)) {
            for (int i = 1; i <= k; i++) {
                ans.push_back(edge(i, i + 1, 1 << (i - 1)));
            }
            bypass(1 << k, L - (1 << k));
            break;
        }
    }
    cout << 20 << " " << ans.size() << endl;
    for (auto e : ans) {
        cout << e.from << " " << e.to << " " << e.cost << endl;
    }
    return 0;
}