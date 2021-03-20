#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    bool spaceFlg = false;
    for (int i = 0; i < s.length(); i++) {
        string v = s.substr(i, 1);
        if (v != " ") {
            cout << v;
            spaceFlg = false;
        } else {
            if (!spaceFlg) {
                cout << ",";
                spaceFlg = true;
            }
        }
    }
    cout << endl;
}