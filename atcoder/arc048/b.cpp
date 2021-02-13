#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> rp(100100, 0);
    int ratep[100100];
    int ph[100100];
    map<pair<int, int>, int> people;
    for (int i = 0; i < N; i++) {
        int R, H;
        cin >> R >> H;
        ratep[i] = R;
        ph[i] = H;
        rp[R]++;
        people[make_pair(R, H)]++;
    }
    for (int i = 0; i < 100010; i++) {
        rp[i + 1] += rp[i];
    }
    for (int p = 0; p < N; p++) {
        int ratew = rp[ratep[p] - 1];  // rateWin
        int jwin = 0;
        int jtmp = 0;
        if (ph[p] == 1) {
            jwin = people[make_pair(ratep[p], 2)];
            jtmp = people[make_pair(ratep[p], 1)];
        } else if (ph[p] == 2) {
            jwin = people[make_pair(ratep[p], 3)];
            jtmp = people[make_pair(ratep[p], 2)];
        } else {
            jwin = people[make_pair(ratep[p], 1)];
            jtmp = people[make_pair(ratep[p], 3)];
        }
        jtmp--;
        cout << ratew + jwin << " " << N - 1 - (ratew + jwin + jtmp) << " "
             << jtmp << endl;
    }
    return 0;
}