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
    int h, w, k;
    cin >> h >> w >> k;
    vc<string> S;
    rep(i, h) {
        string a;
        cin >> a;
        S.push_back(a);
    }
    int ans = 1e9;
    //縦切りを忘れずに足す
    for (int i = 0; i < (1 << (h - 1)); i++) {
        vc<int> to(h);
        int start = 0;
        for (int j = 0; j < h - 1; j++) {
            if (i & (1 << j)) start++;
            to[j] = start;
        }
        vc<int> cnt(start + 1, 0);
        for (int l = 0; l < w; l++) {
            vc<int> now = cnt;
            bool ok = true;
            for (int m = 0; m < h; m++) {
            }
        }
    }