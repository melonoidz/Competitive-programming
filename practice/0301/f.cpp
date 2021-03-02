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
    vc<pair<pi, int>> cnt;
    vc<pair<int, pi>> cnt2;
    rep(i, n) {
        string s;
        cin >> s;
        int tmp = 0;
        int mi = 0;
        int maxmi = s.size();
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                tmp++;
            else {
                tmp--;
            }
            maxmi = min(maxmi, tmp);
        }
        if (tmp > 0) {
            cnt.push_back({pi(tmp, maxmi), tmp - maxmi});
        } else {
            cnt2.push_back({tmp - maxmi, pi(tmp, maxmi)});
        }
    }
    sort(ALL(cnt), greater<pair<pi, int>>());
    bool ok = true;
    int res = 0;
    for (auto c : cnt) {
        if (res + c.first.second < 0) {
            ok = false;
            break;
        }
        res += c.first.first;
        if (res < 0) ok = false;
    }
    for (auto c : cnt2) {
        if (res + c.second.second < 0) {
            ok = false;
            break;
        }
        res += c.second.first;
        if (res < 0) ok = false;
    }
    if (ok && res == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}