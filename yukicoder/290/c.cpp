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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    map<char, vc<int>> cnt;
    for (int i = 0; i < s.size(); i++) {
        cnt[s[i]].push_back(i);
    }
    rep(i, q) {
        int l, r, x;
        cin >> l >> r >> x;
        l--, r--;
        for (char j = 'a'; j <= 'z'; j++) {
            if (cnt[j].size()) {
                auto f = lower_bound(ALL(cnt[j]), l) - cnt[j].begin();
                auto d = lower_bound(ALL(cnt[j]), r + 1) - cnt[j].begin();
                int res = d - f;
                if (x != -1) {
                    if (x <= res) {
                        cout << j << endl;
                        x = -1;
                    } else {
                        x -= res;
                    }
                }
            }
        }
    }
}