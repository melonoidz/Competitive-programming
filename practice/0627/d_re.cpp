#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = numeric_limits<int>::max();

int visited[100010];
int b[100010];

string i_to_s(int num) {
    stringstream ss;
    string res;
    ss << num;
    ss >> res;
    return res;
}

int s_to_i(string num) {
    stringstream ss;
    int res;
    ss << num;
    ss >> res;
    return res;
}

int main(void) {
    int n, a;
    string k;
    cin >> n >> a;
    cin >> k;
    --a;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        --b[i];
        visited[i] = -1;
    }
    visited[a] = 0;
    int now_b = a;
    int step = 0;
    while (true) {
        ++step;
        now_b = b[now_b];
        if (visited[now_b] != -1)
            break;
        else
            visited[now_b] = step;
    }
    int mod = step - visited[now_b];
    string s = i_to_s(step);
    bool inloop;
    if (k.size() > s.size()) {
        inloop = true;
    } else if (s_to_i(k) > step) {
        inloop = true;
    } else {
        inloop = false;
    }
    if (!inloop) {
        int res = a;
        for (int i = 0; i < s_to_i(k); ++i) {
            res = b[res];
        }
        cout << res + 1 << endl;
    } else {
        ll m = 0;
        ll deci = 1;
        for (int i = (int)k.size() - 1; i >= 0; --i) {
            ll p = ((k[i] - '0') * deci) % mod;
            m = (m + p) % mod;
            deci = (deci * 10) % mod;
        }
        m -= step;
        if (m < 0) m += ceil(-m / (double)mod) * mod;
        int res = now_b;
        for (int i = 0; i < m; ++i) {
            res = b[res];
        }
        cout << res + 1 << endl;
    }
    return 0;
}
