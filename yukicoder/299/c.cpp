#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
signed main() {
    using mint = atcoder::modint1000000007;
    long long n;
    cin >> n;
    mint ans = n;
    cout << ans.val() << endl;
}