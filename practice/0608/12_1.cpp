#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        vector<int> p(N);
        for (int j = 0; j < N; j++) {
            cin >> p[j];
        }
        vector<int> a;
        while (true) {
            bool ok = true;
            for (int j = 0; j < N - 1; j++) {
                if (p[j] > p[j + 1]) {
                    ok = false;
                }
            }
            if (ok) {
                break;
            }
            int t = -1;
            for (int j = a.size() % 2; j < N - 1; j += 2) {
                t = j;
                if (p[j] > p[j + 1]) {
                    break;
                }
            }
            a.push_back(t);
            swap(p[t], p[t + 1]);
        }
        int M = a.size();
        cout << M << endl;
        for (int j = 0; j < M; j++) {
            cout << a[j] + 1;
            if (j < M - 1) {
                cout << ' ';
            }
        }
        cout << endl;
    }
}