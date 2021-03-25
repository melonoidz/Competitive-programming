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
    int K, T;
    cin >> K >> T;
    vector<pair<int, int>> vs;
    rep(i, T) {
        int x;
        cin >> x;
        vs.push_back({x, i});
    }
    int last = -1;
    int N = vs.size();
    while (vs.size() > 1) {  // T-1要素すべて消すまで回す。全体でO(K + T)
        sort(ALL(vs));
        for (int i = N - 1; i >= N - 2; i--) {
            if (last != vs[i].second) {
                if (vs[i].first > 0) {
                    last = vs[i].second;
                    vs[i].first--;  // 1個ずつ食べる
                    if (vs[i].first == 0) {
                        vs.erase(vs.begin() + i);  // T-1回しか実行されない
                        N = vs.size();
                    }
                    break;
                }
            }
        }
    }
    cout << vs[0].first - 1 << endl;
    return 0;
}