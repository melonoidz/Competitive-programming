#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, x, n) for (int i = x; i < (n); i++)
#define ALL(n) begin(n), end(n)
#define INF ((1 << 30) - 1)
#define LINF (1LL << 60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;
typedef pair<int, int> pint;
struct cww {
    cww() {
        ios::sync_with_stdio(false);
        cin.tie(0);
    }
} star;

double dist(pint a, pint b) {
    return sqrt((a.first - b.first) * (a.first - b.first) +
                (a.second - b.second) * (a.second - b.second));
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pint> t;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        t.emplace_back(pint(x, y));
    }
    vector<int> vv;
    for (int i = 1; i <= n; i++) vv.emplace_back(i);
    double ans = 0;
    int count = 0;
    do {
        for (int i = 0; i < n - 1; i++) {
            int first = vv[i] - 1;
            int second = vv[i + 1] - 1;
            ans += dist(t[first], t[second]);
        }
        count++;
    } while (next_permutation(vv.begin(), vv.end()));
    cout << fixed << setprecision(50) << ans / (double)count << endl;
    return 0;
}