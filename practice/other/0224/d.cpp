#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
template <class t> using vc = vector<t>;
template <class t> using vvc = vc<vc<t>>;
using pi = pair<int, int>;
using vi = vc<int>;
using uint = unsigned;
using ull = unsigned long long;
signed main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    cin >> n;
    vc<int> dx, dy;
    vc<pi> ball;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ball.emplace_back(x, y);
    }
    sort(ball.begin(), ball.end());
    for (int i = 0; i < n - 1; i++) {
        for (int j = i; j < n; j++) {
            if (i == j) continue;
            int xx = ball[j].first - ball[i].first;
            int yy = ball[j].second - ball[i].second;
            dx.emplace_back(xx);
            dy.emplace_back(yy);
        }
    }
    int cost = n;
    for (int p : dx) {
        for (int q : dy) {
            if (p == 0 && q == 0) continue;
            int res = 0;
            for (int i = 0; i < n - 1; i++) {
                for (int j = i; j < n; j++) {
                    if (i == j) continue;
                    if ((ball[j].first - ball[i].first == p) &&
                        (ball[j].second - ball[i].second == q)) {
                        res++;
                    }
                }
            }
            cost = min(cost, n - res);
        }
    }
    cout << cost << "\n";
}
