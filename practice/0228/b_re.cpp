#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

void make(map<char, char>* data) {
    data->insert(make_pair('b', '1'));
    data->insert(make_pair('c', '1'));
    data->insert(make_pair('d', '2'));
    data->insert(make_pair('w', '2'));
    data->insert(make_pair('t', '3'));
    data->insert(make_pair('j', '3'));
    data->insert(make_pair('f', '4'));
    data->insert(make_pair('q', '4'));
    data->insert(make_pair('l', '5'));
    data->insert(make_pair('v', '5'));
    data->insert(make_pair('s', '6'));
    data->insert(make_pair('x', '6'));
    data->insert(make_pair('p', '7'));
    data->insert(make_pair('m', '7'));
    data->insert(make_pair('h', '8'));
    data->insert(make_pair('k', '8'));
    data->insert(make_pair('n', '9'));
    data->insert(make_pair('g', '9'));
    data->insert(make_pair('z', '0'));
    data->insert(make_pair('r', '0'));

    data->insert(make_pair('B', '1'));
    data->insert(make_pair('C', '1'));
    data->insert(make_pair('D', '2'));
    data->insert(make_pair('W', '2'));
    data->insert(make_pair('T', '3'));
    data->insert(make_pair('J', '3'));
    data->insert(make_pair('F', '4'));
    data->insert(make_pair('Q', '4'));
    data->insert(make_pair('L', '5'));
    data->insert(make_pair('V', '5'));
    data->insert(make_pair('S', '6'));
    data->insert(make_pair('X', '6'));
    data->insert(make_pair('P', '7'));
    data->insert(make_pair('M', '7'));
    data->insert(make_pair('H', '8'));
    data->insert(make_pair('K', '8'));
    data->insert(make_pair('N', '9'));
    data->insert(make_pair('G', '9'));
    data->insert(make_pair('Z', '0'));
    data->insert(make_pair('R', '0'));
}

string solve(const string& str1, map<char, char>& data) {
    string str2;
    map<char, char>::iterator iter;
    for (int i = 0; i < str1.size(); ++i) {
        iter = data.find(str1[i]);
        if (iter == data.end()) continue;
        str2.push_back(iter->second);
    }
    return str2;
}

int main() {
    int i, n;
    string str;
    vector<string> data, ans;
    map<char, char> mapdata;

    make(&mapdata);

    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> str;
        data.push_back(str);
    }

    for (i = 0; i < data.size(); ++i) {
        str = solve(data[i], mapdata);
        if (str.empty()) continue;
        ans.push_back(str);
    }

    if (ans.empty()) {
        cout << endl;
    } else {
        for (i = 0; i < ans.size() - 1; ++i) {
            cout << ans[i] << " ";
        }
        cout << ans[ans.size() - 1] << endl;
    }
    return 0;
}
