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
int T;
int N, A, B, C, D;
map<int, int> memo;
const int LMAX = 1000000000000000000;
int rec(int x) {
    if (x == 0) return 0;
    if (x == 1) return D;
    if (memo.count(x)) return memo[x];  // count あるなら
    int result = LMAX / D > x ? x * D : LMAX;
    int rate, pay;
    rate = 2, pay = A;
    //今のxからup or down で再帰する
    result = min(result, pay + x % rate * D + rec(x / rate));
    result = min(result,
                 pay + abs(rate - x % rate) * D + rec((x + rate - 1) / rate));
    rate = 3, pay = B;
    result = min(result, pay + x % rate * D + rec(x / rate));
    result = min(result,
                 pay + abs(rate - x % rate) * D + rec((x + rate - 1) / rate));
    rate = 5, pay = C;
    result = min(result, pay + x % rate * D + rec(x / rate));
    result = min(result,
                 pay + abs(rate - x % rate) * D + rec((x + rate - 1) / rate));
    return memo[x] = result;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    cin >> T;
    rep(i, T) {
        cin >> N >> A >> B >> C >> D;
        memo.clear();
        cout << rec(N) << endl;
    }
}