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
    map<pair<int, int>, int> cnt;
    rep(i, n) {
        string a;
        cin >> a;
        int tmp = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == '.') tmp = i;
        }
        if (tmp == 0) {
            // zero count
            int zcnt = 0;
            for (int i = a.size() - 1; i >= 0; i--) {
                if (a[i] == '0') {
                    zcnt++;
                } else
                    break;
            }
            if (zcnt != 0) {
                pair<int, int> res;
                res.first = zcnt;
                res.second = zcnt;
                if (a.size() - zcnt - 1 >= 0) {
                    char ll = a[a.size() - zcnt - 1];
                    if (ll == '2') {
                        res.first++;
                    } else if (ll == '4') {
                        res.first += 2;
                    } else if (ll == '5') {
                        res.second++;
                    } else if (ll == '6') {
                        res.first++;
                    } else if (ll == '8') {
                        res.first += 3;
                    }
                }
                cnt[res]++;
            } else {
                char last = a[a.size() - 1];
                if (last == '2') {
                    cnt[pi(1, 0)]++;
                } else if (last == '4') {
                    //...
                }
            }
        }
    }

    return 0;
}