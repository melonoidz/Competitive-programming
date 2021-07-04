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
vc<int> lun;
map<int, int> memo;
const int MAX = 3234566667LL;
void rec(int x) {
    if (x > MAX) return;
    if (memo[x] != 0) return;
    lun.push_back(x);
    memo[x]++;
    for (int i = 0; i < 10; i++) {
        if (abs(x % 10 - i) <= 1) {
            rec(x * 10 + i);
        }
    }
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int k;
    cin >> k;
    for (int i = 1; i < 10; i++) {
        rec(i);
    }
    sort(ALL(lun));
    cout << lun[k - 1] << endl;
}