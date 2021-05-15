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
    string s;
    cin >> s;
    vc<char> tmp;
    for (auto ch : s) tmp.push_back(ch);
    // x=left, y=right
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            string now = s;
            auto res = tmp;
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (cnt > 0) {
                    res[i] = '#';
                    cnt--;
                }
                if (now[i] == '#') {
                    cnt = y;
                }
            }
            string lef;
            cnt = 0;
            rep(i, res.size()) lef += res[i];
            for (int i = n - 1; i >= 0; i--) {
                if (cnt > 0) {
                    res[i] = '#';
                    cnt--;
                }
                if (lef[i] == '#') {
                    cnt = x;
                }
            }
            bool ok = true;
            rep(i, res.size()) {
                if (res[i] != '#') ok = false;
            }
            if (ok) {
                cout << x << " " << y << endl;
                return 0;
            }
        }
    }
}