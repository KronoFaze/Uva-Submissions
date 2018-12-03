#include <bits/stdc++.h>
using namespace std;

bool valid(char c) {
    if(c == '-') return true;
    if(c >= 'a' && c <= 'z') return true;
    if(c >= 'A' && c <= 'Z') return true;
    return false;
}

int main(void) {
    string s, ans, temp;
    while(cin >> s) {
        if(s == "E-N-D") break;
        for(int i = 0; i < s.length(); ++i) {
            if(valid(s[i])) temp.push_back(s[i]);
        }
        if(ans.length() < temp.length()) ans = temp;
        temp.clear();
    }
    transform(ans.begin(), ans.end(), ans.begin(), ::tolower);
    cout << ans << endl;
}
