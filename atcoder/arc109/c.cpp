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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    for (int i = 1; i <= k; i++) {
        string tmp;
        for (int j = 0; j < (1LL << (k - i + 1)); j += 2) {
            if (s[j % n] == 'P') {
                if (s[(j + 1) % n] == 'S') {
                    tmp += s[(j + 1) % n];
                } else {
                    tmp += s[j % n];
                }
            }
            if (s[j % n] == 'R') {
                if (s[(j + 1) % n] == 'P') {
                    tmp += s[(j + 1) % n];
                } else {
                    tmp += s[j % n];
                }
            }
            if (s[j % n] == 'S') {
                if (s[(j + 1) % n] == 'R') {
                    tmp += s[(j + 1) % n];
                } else {
                    tmp += s[j % n];
                }
            }
        }
        s = tmp;
    }
    cout << s << endl;
}