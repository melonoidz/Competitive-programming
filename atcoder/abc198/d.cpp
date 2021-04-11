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
    string a, b, c;
    cin >> a >> b >> c;
    map<char, int> cal;
    map<char, int> res;
    map<char, int> CNT;
    int t = 1;
    for (int i = a.length() - 1; i >= 0; i--) {
        cal[a[i]] += t;
        t *= 10;
        CNT[a[i]]++;
    }
    t = 1;
    for (int i = b.length() - 1; i >= 0; i--) {
        cal[b[i]] += t;
        t *= 10;
        CNT[b[i]]++;
    }
    t = 1;
    for (int i = c.length() - 1; i >= 0; i--) {
        cal[c[i]] -= t;
        t *= 10;
        CNT[c[i]]++;
    }
    int cnt = 0;
    vc<char> al;
    for (auto p : CNT) {
        if (p.second != 0) {
            cnt++;
            al.push_back(p.first);
        }
    }
    if (cnt > 10) {
        cout << "UNSOLVABLE" << endl;
        return 0;
    }
    for (int bit = 0; bit < (1 << 10); bit++) {
        if (popcount(bit) == cnt) {
            vc<int> nums;
            for (int i = 0; i < 10; i++) {
                if (bit & (1 << i)) nums.push_back(i);
            }
            do {
                int result = 0;
                for (int k = 0; k < nums.size(); k++) {
                    result += nums[k] * cal[al[k]];
                    res[al[k]] = nums[k];
                }
                if (result == 0 && ((res[a[0]] != 0) && (res[b[0]] != 0) &&
                                    (res[c[0]] != 0))) {
                    string x, y, z;
                    rep(i, a.length()) { x += to_string(res[a[i]]); }
                    rep(i, b.length()) { y += to_string(res[b[i]]); }
                    rep(i, c.length()) { z += to_string(res[c[i]]); }
                    cout << x << endl;
                    cout << y << endl;
                    cout << z << endl;
                    return 0;
                }
            } while (next_permutation(ALL(nums)));
        }
    }
    cout << "UNSOLVABLE" << endl;
}