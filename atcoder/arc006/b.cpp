#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, L;
    cin >> N >> L;
    cin.ignore();
    vector<string> S(L + 1);
    for (int i = 0; i <= L; i++) {
        getline(cin, S[i]);
    }
    vector<int> p(N);
    for (int i = 0; i < N; i++) {
        p[i] = i;
    }
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (S[i][j * 2 + 1] == '-') {
                swap(p[j], p[j + 1]);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        if (S[L][i * 2] == 'o') {
            cout << p[i] + 1 << endl;
        }
    }
}