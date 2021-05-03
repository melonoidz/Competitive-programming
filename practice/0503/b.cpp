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
    int all = 10000000000LL;
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n < 3) {
        if (s == "1") {
            cout << all * 2 << endl;
        }
        if (s == "11") {
            cout << all << endl;
        }
        if (s == "0") {
            cout << all << endl;
        }
        return 0;
    }
    if (s.size() > 1 && s[0] == '0')
        s = s.substr(1), all--;
    else if (s.size() > 2 && s.substr(0, 2) == "10")
        s = s.substr(2), all--;
    
}