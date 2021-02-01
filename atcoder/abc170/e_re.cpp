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
int N, Q;
const int M = 200000;
vc<multiset<int>> st(M);
vc<int> A, B;
multiset<int> maxes;

void del(int ns, int rate, multiset<int>& maxes) {
    if (st[ns].size()) maxes.erase(maxes.find(*st[ns].rbegin()));
    st[ns].erase(st[ns].find(rate));
    if (st[ns].size()) maxes.insert(*st[ns].rbegin());
}
void add(int ns, int rate, multiset<int>& maxes) {
    if (st[ns].size()) maxes.erase(maxes.find(*st[ns].rbegin()));
    st[ns].insert(rate);
    if (st[ns].size()) maxes.insert(*st[ns].rbegin());
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    std::cout << fixed << setprecision(20);
    cin >> N >> Q;
    A.resize(N);
    B.resize(N);
    rep(i, N) {
        cin >> A[i] >> B[i];
        B[i]--;
        st[B[i]].insert(A[i]);
    }
    rep(i, M) {
        if (st[i].size()) {
            maxes.insert(*st[i].rbegin());
        }
    }
    while (Q--) {
        int c, d;
        cin >> c >> d;
        c--, d--;
        int bef = B[c];
        B[c] = d;  // to d
        del(bef, A[c], maxes);
        add(d, A[c], maxes);
        std::cout << *maxes.begin() << endl;
    }
    return 0;
}