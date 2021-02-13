#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> D(N);
    int mx = 0;
    int secmx = 0;
    int ans = 30;
    for (int i = 0; i < N; i++) {
        cin >> D[i];
    }
    vector<int> time;
    D.push_back(0);
    sort(D.begin(), D.end());
    for (int i = 0; i < D.size(); i++) {
        if (i % 2 == 0) {
            time.push_back((0 + D[i]) % 24);
        } else {
            time.push_back((0 - D[i] + 24) % 24);
        }
    }
    sort(time.begin(), time.end());
    for (int i = 0; i < time.size() - 1; i++) {
        ans = min(ans, time[i + 1] - time[i]);
    }
    cout << min(ans, 24 - time[time.size() - 1]) << endl;
    return 0;
}