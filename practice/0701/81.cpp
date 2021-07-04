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
    int N, K;
    cin >> N >> K;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
    }
    int R = max(*max_element(A.begin(), A.end()), K) + 1;
    int C = max(*max_element(B.begin(), B.end()), K) + 1;
    vector<vector<int>> sum(R + 1, vector<int>(C + 1));
    for (int i = 0; i < N; ++i) {
        ++sum[A[i] + 1][B[i] + 1];
    }
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            sum[i][j] += sum[i - 1][j];
        }
    }
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            sum[i][j] += sum[i][j - 1];
        }
    }
    int answer = 0;
    for (int i = 0; i <= R - K - 1; ++i) {
        for (int j = 0; j <= C - K - 1; ++j) {
            answer = max(answer, sum[i][j] + sum[i + K + 1][j + K + 1] -
                                     sum[i][j + K + 1] - sum[i + K + 1][j]);
        }
    }
    cout << answer << endl;
}