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
    string a;
    cin >> a;
    if (a == "a" || a == "zzzzzzzzzzzzzzzzzzzz") {
        cout << "NO" << endl;
        return 0;
    }
    if (a.length() == 1) {
        int cnt = a[0] - 'a';
        string tmp;
        tmp += "a";
        cnt--;
        tmp += 'a' + cnt;
        cout << tmp << endl;
        return 0;
    }
    bool same = true;
    for (int i = 0; i < a.length() - 1; i++) {
        if (a[i] != a[i + 1]) same = false;
    }
    if (!same) {
        reverse(ALL(a));
        cout << a << endl;
        return 0;
    }
    int cnt = 0;
    for (auto y : a) {
        cnt += y - 'a' + 1;
    }
    string ans;
    while (cnt > 0) {
        int num = min(cnt, 26LL);
        char q = ('a' + num - 1);
        ans += q;
        cnt -= num;
    }
    if (ans == a) {
        ans = ans.substr(1);
        ans += "ya";
    }
    cout << ans << endl;
}