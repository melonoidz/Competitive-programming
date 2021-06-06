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
    vc<int> two, thr, fiv;
    if (n > 4) {
        for (int i = 4; i <= n; i += 2) {
            if (i % 3 != 0 && i % 5 != 0) {
                two.push_back(i);
            }
        }
    }
    if (n > 9) {
        for (int i = 9; i <= n; i += 3) {
            if (i % 2 != 0 && i % 5 != 0) {
                thr.push_back(i);
            }
        }
    }
    if (n > 15) {
        for (int i = 15; i <= n; i += 5) {
            if (i % 2 != 0 && i % 3 != 0) {
                fiv.push_back(i);
            }
        }
    }
    vc<int> ans;
    ans.push_back(3);
    int l;
    if (n % 2 != 0)
        l = n / 2 + 1;
    else
        l = n / 2;
    int cnt = l;
    if (!thr.empty()) {
        for (int i = 0; i < min(cnt / 2, int(thr.size())); i++) {
            ans.push_back(thr[i]);
        }
    }
    // rep(i, ans.size()) cout << ans[i] << "--";
    cnt -= ans.size();
    ans.push_back(6);
    ans.push_back(2);
    cnt -= 2;
    if (!two.empty()) {
        for (int i = 0; i < min(cnt, int(two.size())) - 2; i++) {
            ans.push_back(two[i]);
        }
    }
    ans.push_back(10);
    ans.push_back(5);
    if (!fiv.empty()) {
        int st = 0;
        while (ans.size() < l) {
            ans.push_back(fiv[st]);
            st++;
        }
    }
    rep(i, min(l, int(ans.size()))) cout << ans[i] << " ";
    cout << endl;
}