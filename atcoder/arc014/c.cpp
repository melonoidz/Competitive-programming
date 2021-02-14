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
    string s;
    cin >> s;
    int cnt[3] = {0};
    for (auto li : s) {
        if (li == 'R') {
            cnt[0]++;
        } else if (li == 'G') {
            cnt[1]++;
        } else
            cnt[2]++;
    }
    int tmp = 0;
    for (auto c : cnt)
        if (c % 2 == 1) tmp++;
    if (tmp == 0)
        cout << 0 << endl;
    else if (tmp == 1)
        cout << 1 << endl;
    else if (tmp == 2)
        cout << 2 << endl;
    else
        cout << 3 << endl;
    return 0;
}