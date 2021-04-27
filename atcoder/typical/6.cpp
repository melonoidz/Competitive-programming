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
    vc<vc<int>> nex(100100, vc<int>(26));
    // nex[i][j]：i文字目の右にある文字jの中で，最も左側にあるもののインデックス(何文字目にあるか？)
    for (int i = 0; i < 26; i++) nex[s.size()][i] = s.size();
    for (int i = (int)s.size() - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            if ((int)s[i] - 'a' == j) {
                nex[i][j] = i;
            } else {
                nex[i][j] = nex[i + 1][j];
            }
        }
    }
    // rep(i, s.size()) {
    //     rep(j, 26) { cout << nex[i][j] << " "; }
    //     cout << endl;
    // }
    string ans = "";
    int cur = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < 26; j++) {
            int next = nex[cur][j];
            int maxlength = s.size() - next - 1 + i;
            if (maxlength >= k) {
                ans += 'a' + j;
                cur = next + 1;
                break;
            }
        }
    }
    cout << ans << endl;
}