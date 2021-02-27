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
    string s;
    cin >> s;
    map<char, int> cnt;
    for (auto m : s) {
        cnt[m]++;
    }
    vc<int> odd, even;
    for (auto c : cnt) {
        if (c.second % 2 == 0) {
            even.push_back(c.second);
        } else {
            odd.push_back(c.second);
        }
    }
    if (odd.size() < 2) {
        cout << s.size() << endl;
        return 0;
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end(), greater<int>());
    if (odd.size() > even.size()) {
        cout << odd.back() << endl;
        return 0;
    }
    //ここがダメ
    int ans = odd.back() + even.back();
    cout << ans << endl;
}