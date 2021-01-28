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
    string s;
    cin >> s;
    vc<string> first{"SS", "SW", "WW", "WS"};
    for (auto f : first) {
        string tmp = f;
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == 'o') {
                if (tmp[i] == 'S') {
                    tmp.push_back(tmp[i - 1]);
                } else {
                    if (tmp[i - 1] == 'S') {
                        tmp.push_back('W');
                    } else {
                        tmp.push_back('S');
                    }
                }
            } else {
                if (tmp[i] == 'S') {
                    if (tmp[i - 1] == 'S') {
                        tmp.push_back('W');
                    } else {
                        tmp.push_back('S');
                    }
                } else {
                    tmp.push_back(tmp[i - 1]);
                }
            }
        }
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (s[i] == 'o') {
                    if (tmp[i] == 'S') {
                        ok = (tmp[i + 1] == tmp[n - 1]);
                    } else {
                        ok = (tmp[1] != tmp[n - 1]);
                    }
                } else {
                    if (tmp[i] == 'S') {
                        ok = (tmp[i + 1] != tmp[n - 1]);
                    } else {
                        ok = (tmp[1] == tmp[n - 1]);
                    }
                }
                if (!ok) break;
            } else if (i == n - 1) {
                if (s[i] == 'o') {
                    if (tmp[i] == 'S') {
                        ok = (tmp[0] == tmp[n - 2]);
                    } else {
                        ok = (tmp[0] != tmp[n - 2]);
                    }
                } else {
                    if (tmp[i] == 'S') {
                        ok = (tmp[0] != tmp[n - 2]);
                    } else {
                        ok = (tmp[0] == tmp[n - 2]);
                    }
                }
                if (!ok) break;
            } else {
                if (s[i] == 'o') {
                    if (tmp[i] == 'S') {
                        ok = (tmp[i - 1] == tmp[i + 1]);
                    } else {
                        ok = (tmp[i - 1] != tmp[i + 1]);
                    }
                } else {
                    if (tmp[i] == 'S') {
                        ok = (tmp[i - 1] != tmp[i + 1]);
                    } else {
                        ok = (tmp[i - 1] == tmp[i + 1]);
                    }
                }
                if (!ok) break;
            }
        }
        if (ok) {
            cout << tmp << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}