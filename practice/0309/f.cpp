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
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    int ans = 0;
    // num=(s[i]^10(s.length()-1)-s[i+j]^10(s.length()-(j+1))))/10^(s.length()-(j+1))
    // mod P でみて=0? 2,5 ??
    if (p == 2) {
        for (int i = 0; i < s.length(); i++) {
            int num = s[i] - '0';
            if (num % 2 == 0 || num == 0) {
                ans += i + 1;
            }
        }
    } else if (p == 5) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0' || s[i] == '5') {
                ans += i + 1;
            }
        }
    } else {
        map<int, int> cnt;
        int tmp = 1;
        int res = 0;
        reverse(ALL(s));
        cnt[0]++;
        for (int i = 0; i < s.length(); i++) {
            int num = s[i] - '0';
            res += num * tmp;
            tmp *= 10;
            tmp %= p;
            res %= p;
            if (res < 0) res += p;
            if (tmp < 0) tmp += p;
            cnt[res]++;
        }
        for (auto q : cnt) {
            ans += q.second * (q.second - 1) / 2;
        }
    }
    cout << ans << endl;
}