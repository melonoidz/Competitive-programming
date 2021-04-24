#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }
    int M;
    cin >> M;
    vector<int> XX(M + 1), XY(M + 1);
    vector<long long> XP(M + 1);
    vector<int> YX(M + 1), YY(M + 1);
    vector<long long> YP(M + 1);
    XX[0] = 1;
    XY[0] = 0;
    XP[0] = 0;
    YX[0] = 0;
    YY[0] = 1;
    YP[0] = 0;
    for (int i = 0; i < M; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            XX[i + 1] = YX[i];
            XY[i + 1] = YY[i];
            XP[i + 1] = YP[i];
            YX[i + 1] = -XX[i];
            YY[i + 1] = -XY[i];
            YP[i + 1] = -XP[i];
        }
        if (t == 2) {
            XX[i + 1] = -YX[i];
            XY[i + 1] = -YY[i];
            XP[i + 1] = -YP[i];
            YX[i + 1] = XX[i];
            YY[i + 1] = XY[i];
            YP[i + 1] = XP[i];
        }
        if (t == 3) {
            int p;
            cin >> p;
            XX[i + 1] = -XX[i];
            XY[i + 1] = -XY[i];
            XP[i + 1] = p * 2 - XP[i];
            YX[i + 1] = YX[i];
            YY[i + 1] = YY[i];
            YP[i + 1] = YP[i];
        }
        if (t == 4) {
            int p;
            cin >> p;
            XX[i + 1] = XX[i];
            XY[i + 1] = XY[i];
            XP[i + 1] = XP[i];
            YX[i + 1] = -YX[i];
            YY[i + 1] = -YY[i];
            YP[i + 1] = p * 2 - YP[i];
        }
    }
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int A, B;
        cin >> A >> B;
        B--;
        long long x = XX[A] * X[B] + XY[A] * Y[B] + XP[A];
        long long y = YX[A] * X[B] + YY[A] * Y[B] + YP[A];
        cout << x << ' ' << y << endl;
    }
}