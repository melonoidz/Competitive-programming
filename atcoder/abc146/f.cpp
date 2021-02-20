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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int count = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            count++;
        } else {
            count = 0;
        }
        if (count == m) {
            cout << -1 << endl;
            return 0;
        }
    }
    vc<int> cnt(n + 1, 0);
    reverse(s.begin(), s.end());
    int turn = 1;
    int st = 0;
    int now = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            if (i - st < m) {
                continue;
            } else if (i - st == m) {
                i = now;
                st = now;
                turn++;
            }
        } else {
            if (i - st < m) {
                cnt[i] = turn;
                now = i;
            } else if (i - st == m) {
                cnt[i] = turn;
                turn++;
                st = i;
            }
        }
    }
    for (int i = cnt.size() - 1; i >= 0; i--) {
        if (cnt[i] == 0) {
            cnt[i] = cnt[i + 1];
        }
    }
    // rep(i, cnt.size()) { cout << i << " i " << cnt[i] << " turn " << endl; }
    vc<int> ans;
    int tmp = 0;
    int nw = cnt[1];
    cnt.push_back(0);
    for (int i = 1; i < cnt.size(); i++) {
        if (cnt[i] == nw) {
            tmp++;
        } else {
            ans.push_back(tmp);
            tmp = 1;
            nw = cnt[i];
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto res : ans) {
        cout << res << " ";
    }
    cout << endl;
    return 0;
}