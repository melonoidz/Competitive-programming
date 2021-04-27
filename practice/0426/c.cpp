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
    vc<vc<int>> cnt(4010, vc<int>(3, 0));
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
            cnt[i + 1][0] += cnt[i][0] + 1;
            cnt[i + 1][1] += cnt[i][1];
            cnt[i + 1][2] += cnt[i][2];

        } else if (s[i] == 'G') {
            cnt[i + 1][1] += cnt[i][1] + 1;
            cnt[i + 1][0] += cnt[i][0];
            cnt[i + 1][2] += cnt[i][2];

        } else {
            cnt[i + 1][2] += cnt[i][2] + 1;
            cnt[i + 1][1] += cnt[i][1];
            cnt[i + 1][0] += cnt[i][0];
        }
    }
    int ans = 0;
    for (int j = 1; j < n - 1; j++) {
        for (int k = j + 1; k < n; k++) {
            if (s[j] == 'R') {
                if (s[k] == 'G') {
                    int tmp = cnt[j + 1][2];
                    if (s[j - (k - j)] == 'B') {
                        ans += tmp - 1;
                    } else {
                        ans += tmp;
                    }
                } else if (s[k] == 'B') {
                    int tmp = cnt[j + 1][1];
                    if (s[j - (k - j)] == 'G') {
                        ans += tmp - 1;
                    } else {
                        ans += tmp;
                    }
                }
            }
            if (s[j] == 'G') {
                if (s[k] == 'R') {
                    int tmp = cnt[j + 1][2];
                    if (s[j - (k - j)] == 'B') {
                        ans += tmp - 1;
                    } else {
                        ans += tmp;
                    }

                } else if (s[k] == 'B') {
                    int tmp = cnt[j + 1][0];
                    if (s[j - (k - j)] == 'R') {
                        ans += tmp - 1;
                    } else {
                        ans += tmp;
                    }
                }
            }
            if (s[j] == 'B') {
                if (s[k] == 'R') {
                    int tmp = cnt[j + 1][1];
                    if (s[j - (k - j)] == 'G') {
                        ans += tmp - 1;
                    } else {
                        ans += tmp;
                    }
                } else if (s[k] == 'G') {
                    int tmp = cnt[j + 1][0];
                    if (s[j - (k - j)] == 'R') {
                        ans += tmp - 1;
                    } else {
                        ans += tmp;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}