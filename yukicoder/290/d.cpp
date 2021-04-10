#include <bits/stdc++.h>
using namespace std;
signed main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << 9 << " " << 1 << endl;
    } else {
        cout << 26 + (n - 1) * 18 << " " << 1 << endl;
    }
}