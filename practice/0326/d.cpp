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
    string S;
    cin >> S;
    int ans = S.size() / 2;
    vc<vc<int>> cnt(26);
    for (int i = 0; i < S.size(); i++) {
        int now = S[i] - 'a';
        cnt[now].push_back(i + 1);
    }
    vc<int> num;
    int d = 0;
    rep(i, 26) {
        if (!cnt[i].empty()) {
            if (d == cnt[i].size()) {
                num.push_back(i);
            }
            if (d < cnt[i].size()) {
                d = cnt[i].size();
                vc<int> y;
                y.push_back(i);
                num = y;
            }
        }
    }
    int tmp = 1e9;
    for (int i = 0; i < num.size(); i++) {
        int dist = 0;
        for (int j = 0; j < cnt[num[i]].size() - 1; i++) {
            dist = max(dist, cnt[num[i]][j + 1] - cnt[num[i]][j]);
        }
        ans = dist;
    }
    cout << ans << endl;
}