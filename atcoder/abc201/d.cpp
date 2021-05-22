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
    int h, w;
    cin >> h >> w;
    vc<string> a;
    rep(i, h) {
        string g;
        cin >> g;
        a.push_back(g);
    }
    // h+w=2k Aoki last else Takahashi last
    // h+w-1 )//2ラウンド
    int last = (h + w - 2) % 2;
    vc<vc<pi>> dp(2010, vc<pi>(2010));
    dp[h - 1][w - 1] = pi(100, 100);
    queue<pair<pi, pi>> q;
    q.push(make_pair(pi(h - 1, w - 1), pi(100, 100)));
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        auto nh = p.first.first;
        auto nw = p.first.second;
        auto nt = p.second.first;
        auto na = p.second.second;
        if (last == 0) {
            // Aokiから
            if (a[nh][nw] == '-') {
                // up
                if (nh - 1 >= 0) {
                    if (a[nh - 1][nw] == '+') {
                        if (nh - 2 >= 0) {
                            auto tmp = dp[nh - 2][nw];
                            if (tmp == pi(0, 0)) {
                                dp[nh - 2][nw] = pi(nt + 1, na - 1);
                            } else {
                                if ((tmp.first - tmp.second) <
                                    (nt + 1 - (na - 1))) {
                                    dp[nh - 2][nw] = pi(nt + 1, na - 1);
                                }
                            }
                            q.push(make_pair(pi(nh - 2, nw), dp[nh - 2][nw]));
                        }
                        if (nw - 1 >= 0) {
                            auto tmp = dp[nh - 1][nw - 1];
                            if (tmp == pi(0, 0)) {
                                dp[nh - 1][nw - 1] = pi(nt + 1, na - 1);
                            } else {
                                if ((tmp.first - tmp.second) <
                                    (nt + 1 - (na - 1))) {
                                    dp[nh - 1][nw - 1] = pi(nt + 1, na - 1);
                                }
                            }
                            q.push(make_pair(pi(nh - 1, nw - 1),
                                             dp[nh - 1][nw - 1]));
                        }
                    }
                    //-
                    if (a[nh - 1][nw] == '-') {
                        if (nh - 2 >= 0) {
                            // auto tmp = dp[nh - 2][nw];
                            // if (tmp.first - tmp.second < nt - na) {
                            //     dp[nh - 2][nw] = pi(nt, na);
                            // }
                            q.push(make_pair(pi(nh - 2, nw), pi(nt, na)));
                        }
                        if (nw - 1 >= 0) {
                            // auto tmp = dp[nh - 1][nw - 1];
                            // if (tmp.first - tmp.second < nt - na) {
                            //     dp[nh - 1][nw - 1] = pi(nt, na);
                            // }
                            q.push(make_pair(pi(nh - 1, nw - 1), pi(nt, na)));
                        }
                    }
                }
                // left
                if (nw - 1 >= 0) {
                    if (a[nh][nw - 1] == '+') {
                        if (nw - 2 >= 0) {
                            auto tmp = dp[nh][nw - 2];
                            if (tmp == pi(0, 0)) {
                                dp[nh][nw - 2] = pi(nt + 1, na - 1);
                            } else {
                                if ((tmp.first - tmp.second) <
                                    (nt + 1 - (na - 1))) {
                                    dp[nh][nw - 2] = pi(nt + 1, na - 1);
                                }
                            }
                            q.push(make_pair(pi(nh, nw - 2), dp[nh][nw - 2]));
                        }
                        if (nh - 1 >= 0) {
                            auto tmp = dp[nh - 1][nw - 1];
                            if (tmp == pi(0, 0)) {
                                dp[nh - 1][nw - 1] = pi(nt + 1, na - 1);
                            } else {
                                if ((tmp.first - tmp.second) <
                                    (nt + 1 - (na - 1))) {
                                    dp[nh - 1][nw - 1] = pi(nt + 1, na - 1);
                                }
                            }
                            q.push(make_pair(pi(nh - 1, nw - 1),
                                             dp[nh - 1][nw - 1]));
                        }
                    }
                    //-
                    if (a[nh][nw - 1] == '-') {
                        if (nw - 2 >= 0) {
                            // auto tmp = dp[nh][nw - 2];
                            // if (tmp.first - tmp.second < nt - na) {
                            //     dp[nh][nw - 2] = pi(nt, na);
                            // }
                            q.push(make_pair(pi(nh, nw - 2), pi(nt, na)));
                        }
                        if (nh - 1 >= 0) {
                            // auto tmp = dp[nh - 1][nw - 1];
                            // if (tmp.first - tmp.second < nt - na) {
                            //     dp[nh - 1][nw - 1] = pi(nt, na);
                            // }
                            q.push(make_pair(pi(nh - 1, nw - 1), pi(nt, na)));
                        }
                    }
                }
            }
            //++
            if (a[nh][nw] == '+') {
                // up
                if (nh - 1 >= 0) {
                    if (a[nh - 1][nw] == '+') {
                        if (nh - 2 >= 0) {
                            // auto tmp = dp[nh - 2][nw];
                            // if ((tmp.first - tmp.second) < (nt - na)) {
                            //     dp[nh - 2][nw] = pi(nt, na);
                            // }
                            q.push(make_pair(pi(nh - 2, nw), pi(nt, na)));
                        }
                        if (nw - 1 >= 0) {
                            // auto tmp = dp[nh - 1][nw - 1];
                            // if ((tmp.first - tmp.second) < (nt - na)) {
                            //     dp[nh - 1][nw - 1] = pi(nt, na);
                            // }
                            q.push(make_pair(pi(nh - 1, nw - 1), pi(nt, na)));
                        }
                    }
                    //-
                    if (a[nh - 1][nw] == '-') {
                        if (nh - 2 >= 0) {
                            auto tmp = dp[nh - 2][nw];
                            if (tmp == pi(0, 0)) {
                                dp[nh - 2][nw] = pi(nt - 1, na + 1);
                            } else {
                                if (tmp.first - tmp.second <
                                    nt - 1 - (na + 1)) {
                                    dp[nh - 2][nw] = pi(nt - 1, na + 1);
                                }
                            }
                            q.push(make_pair(pi(nh - 2, nw), dp[nh - 2][nw]));
                        }
                        if (nw - 1 >= 0) {
                            auto tmp = dp[nh - 1][nw - 1];
                            if (tmp == pi(0, 0)) {
                                dp[nh - 1][nw - 1] = pi(nt - 1, na + 1);
                            } else {
                                if (tmp.first - tmp.second <
                                    nt - 1 - (na + 1)) {
                                    dp[nh - 1][nw - 1] = pi(nt - 1, na + 1);
                                }
                            }
                            q.push(make_pair(pi(nh - 1, nw - 1),
                                             dp[nh - 1][nw - 1]));
                        }
                    }
                }
                // left
                if (nw - 1 >= 0) {
                    if (a[nh][nw - 1] == '+') {
                        if (nw - 2 >= 0) {
                            // auto tmp = dp[nh][nw - 2];
                            // if ((tmp.first - tmp.second) < (nt - na)) {
                            //     dp[nh][nw - 2] = pi(nt, na);
                            // }
                            q.push(make_pair(pi(nh, nw - 2), pi(nt, na)));
                        }
                        if (nh - 1 >= 0) {
                            // auto tmp = dp[nh - 1][nw - 1];
                            // if ((tmp.first - tmp.second) < (nt - na)) {
                            //     dp[nh - 1][nw - 1] = pi(nt, na);
                            // }
                            q.push(make_pair(pi(nh - 1, nw - 1), pi(nt, na)));
                        }
                    }
                    //-
                    if (a[nh][nw - 1] == '-') {
                        if (nw - 2 >= 0) {
                            auto tmp = dp[nh][nw - 2];
                            if (tmp == pi(0, 0)) {
                                dp[nh][nw - 2] = pi(nt - 1, na + 1);
                            } else {
                                if (tmp.first - tmp.second < nt - 1 - na - 1) {
                                    dp[nh][nw - 2] = pi(nt - 1, na + 1);
                                }
                            }
                            q.push(make_pair(pi(nh, nw - 2), dp[nh][nw - 2]));
                        }
                        if (nh - 1 >= 0) {
                            auto tmp = dp[nh - 1][nw - 1];
                            if (tmp == pi(0, 0)) {
                                dp[nh - 1][nw - 1] = pi(nt - 1, na + 1);
                            } else {
                                if (tmp.first - tmp.second < nt - 1 - na - 1) {
                                    dp[nh - 1][nw - 1] = pi(nt - 1, na + 1);
                                }
                            }
                            q.push(make_pair(pi(nh - 1, nw - 1),
                                             dp[nh - 1][nw - 1]));
                        }
                    }
                }
            }
            last = 1;
        } else {
            // Takahashiから
            if (a[nh][nw] == '-') {
                // up
                if (nh - 1 >= 0) {
                    if (a[nh - 1][nw] == '+') {
                        if (nh - 2 >= 0) {
                            auto tmp = dp[nh - 2][nw];
                            if (tmp == pi(0, 0)) {
                                dp[nh - 2][nw] = pi(nt - 1, na + 1);
                            } else {
                                if ((tmp.first - tmp.second) <
                                    (nt - 1 - (na + 1))) {
                                    dp[nh - 2][nw] = pi(nt - 1, na + 1);
                                }
                            }
                            q.push(make_pair(pi(nh - 2, nw), dp[nh - 2][nw]));
                        }
                        if (nw - 1 >= 0) {
                            auto tmp = dp[nh - 1][nw - 1];
                            if (tmp == pi(0, 0)) {
                                dp[nh - 1][nw - 1] = pi(nt - 1, na + 1);
                            } else {
                                if ((tmp.first - tmp.second) <
                                    (nt - 1 - (na + 1))) {
                                    dp[nh - 1][nw - 1] = pi(nt - 1, na + 1);
                                }
                            }
                            q.push(make_pair(pi(nh - 1, nw - 1),
                                             dp[nh - 1][nw - 1]));
                        }
                    }
                    //-
                    if (a[nh - 1][nw] == '-') {
                        if (nh - 2 >= 0) {
                            // auto tmp = dp[nh - 2][nw];
                            // if (tmp.first - tmp.second < nt - na) {
                            //     dp[nh - 2][nw] = pi(nt, na);
                            // }
                            q.push(make_pair(pi(nh - 2, nw), pi(nt, na)));
                        }
                        if (nw - 1 >= 0) {
                            // auto tmp = dp[nh - 1][nw - 1];
                            // if (tmp.first - tmp.second < nt - na) {
                            //     dp[nh - 1][nw - 1] = pi(nt, na);
                            // }
                            q.push(make_pair(pi(nh - 1, nw - 1), pi(nt, na)));
                        }
                    }
                }
                // left
                if (nw - 1 >= 0) {
                    if (a[nh][nw - 1] == '+') {
                        if (nw - 2 >= 0) {
                            auto tmp = dp[nh][nw - 2];
                            if (tmp == pi(0, 0)) {
                                dp[nh][nw - 2] = pi(nt - 1, na + 1);
                            } else {
                                if ((tmp.first - tmp.second) <
                                    (nt - 1 - (na + 1))) {
                                    dp[nh][nw - 2] = pi(nt - 1, na + 1);
                                }
                            }
                            q.push(make_pair(pi(nh, nw - 2), dp[nh][nw - 2]));
                        }
                        if (nh - 1 >= 0) {
                            auto tmp = dp[nh - 1][nw - 1];
                            if (tmp == pi(0, 0)) {
                                dp[nh - 1][nw - 1] = pi(nt - 1, na + 1);
                            } else {
                                if ((tmp.first - tmp.second) <
                                    (nt - 1 - (na + 1))) {
                                    dp[nh - 1][nw - 1] = pi(nt - 1, na + 1);
                                }
                            }
                            q.push(make_pair(pi(nh - 1, nw - 1),
                                             dp[nh - 1][nw - 1]));
                        }
                    }
                    //-
                    if (a[nh][nw - 1] == '-') {
                        if (nw - 2 >= 0) {
                            // auto tmp = dp[nh][nw - 2];
                            // if (tmp.first - tmp.second < nt - na) {
                            //     dp[nh][nw - 2] = pi(nt, na);
                            // }
                            q.push(make_pair(pi(nh, nw - 2), pi(nt, na)));
                        }
                        if (nh - 1 >= 0) {
                            // auto tmp = dp[nh - 1][nw - 1];
                            // if (tmp.first - tmp.second < nt - na) {
                            //     dp[nh - 1][nw - 1] = pi(nt, na);
                            // }
                            q.push(make_pair(pi(nh - 1, nw - 1), pi(nt, na)));
                        }
                    }
                }
            }
            //++
            if (a[nh][nw] == '+') {
                // up
                if (nh - 1 >= 0) {
                    if (a[nh - 1][nw] == '+') {
                        if (nh - 2 >= 0) {
                            // auto tmp = dp[nh - 2][nw];
                            // if ((tmp.first - tmp.second) < (nt - na)) {
                            //     dp[nh - 2][nw] = pi(nt, na);
                            // }
                            q.push(make_pair(pi(nh - 2, nw), pi(nt, na)));
                        }
                        if (nw - 1 >= 0) {
                            // auto tmp = dp[nh - 1][nw - 1];
                            // if ((tmp.first - tmp.second) < (nt - na)) {
                            //     dp[nh - 1][nw - 1] = pi(nt, na);
                            // }
                            q.push(make_pair(pi(nh - 1, nw - 1), pi(nt, na)));
                        }
                    }
                    //-
                    if (a[nh - 1][nw] == '-') {
                        if (nh - 2 >= 0) {
                            auto tmp = dp[nh - 2][nw];
                            if (tmp == pi(0, 0)) {
                                dp[nh - 2][nw] = pi(nt + 1, na - 1);
                            } else {
                                if (tmp.first - tmp.second <
                                    nt + 1 - (na - 1)) {
                                    dp[nh - 2][nw] = pi(nt + 1, na - 1);
                                }
                            }
                            q.push(make_pair(pi(nh - 2, nw), dp[nh - 2][nw]));
                        }
                        if (nw - 1 >= 0) {
                            auto tmp = dp[nh - 1][nw - 1];
                            if (tmp == pi(0, 0)) {
                                dp[nh - 1][nw - 1] = pi(nt + 1, na - 1);
                            } else {
                                if (tmp.first - tmp.second <
                                    nt + 1 - (na - 1)) {
                                    dp[nh - 1][nw - 1] = pi(nt + 1, na - 1);
                                }
                            }
                            q.push(make_pair(pi(nh - 1, nw - 1),
                                             dp[nh - 1][nw - 1]));
                        }
                    }
                }
                // left
                if (nw - 1 >= 0) {
                    if (a[nh][nw - 1] == '+') {
                        if (nw - 2 >= 0) {
                            // auto tmp = dp[nh][nw - 2];
                            // if ((tmp.first - tmp.second) < (nt - na)) {
                            //     dp[nh][nw - 2] = pi(nt, na);
                            // }
                            q.push(make_pair(pi(nh, nw - 2), pi(nt, na)));
                        }
                        if (nh - 1 >= 0) {
                            // auto tmp = dp[nh - 1][nw - 1];
                            // if ((tmp.first - tmp.second) < (nt - na)) {
                            //     dp[nh - 1][nw - 1] = pi(nt, na);
                            // }
                            q.push(make_pair(pi(nh - 1, nw - 1), pi(nt, na)));
                        }
                    }
                    //-
                    if (a[nh][nw - 1] == '-') {
                        if (nw - 2 >= 0) {
                            auto tmp = dp[nh][nw - 2];
                            if (tmp == pi(0, 0)) {
                                dp[nh][nw - 2] = pi(nt + 1, na - 1);
                            } else {
                                if (tmp.first - tmp.second < nt + 1 - na + 1) {
                                    dp[nh][nw - 2] = pi(nt + 1, na - 1);
                                }
                            }
                            q.push(make_pair(pi(nh, nw - 2), dp[nh][nw - 2]));
                        }
                        if (nh - 1 >= 0) {
                            auto tmp = dp[nh - 1][nw - 1];
                            if (tmp == pi(0, 0)) {
                                dp[nh - 1][nw - 1] = pi(nt + 1, na - 1);
                            } else {
                                if (tmp.first - tmp.second < nt + 1 - na + 1) {
                                    dp[nh - 1][nw - 1] = pi(nt + 1, na - 1);
                                }
                            }
                            q.push(make_pair(pi(nh - 1, nw - 1),
                                             dp[nh - 1][nw - 1]));
                        }
                    }
                }
            }
            last = 0;
        }
    }
    auto res = dp[0][0];
    if (res.first > res.second) {
        cout << "Takahashi" << endl;
    } else if (res.first < res.second) {
        cout << "Aoki" << endl;
    } else {
        cout << "Draw" << endl;
    }
}