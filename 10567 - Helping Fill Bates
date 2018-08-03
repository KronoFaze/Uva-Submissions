#include <bits/stdc++.h>
using namespace std;

bool cmp(pair <char, int> x, pair <char, int> y) {
    if(x.first == y.first) return x.second < y.second;
    return x.first < y.first;
}

int binarySearch(int lastPos, char target, vector < pair <char, int> > &vp) {
    int ret = -1;
    int left = 0, right = vp.size() - 1;
    while(left <= right) {
        int mid = left + ((right - left) >> 1);
        if(vp[mid].first == target && vp[mid].second > lastPos) {
            ret = mid;
            right = mid - 1;
        }
        else if(vp[mid].first > target) right = mid - 1;
        else left = mid + 1;
    }
    return ret;
}

int main(void)
{
    string s;
    cin >> s;
    vector < pair <char, int> > vp;
    for(int i = 0; i < s.length(); ++i) vp.push_back({s[i], i});
    sort(vp.begin(), vp.end(), cmp);
    int q;
    cin >> q;
    while(q--) {
        string ss;
        cin >> ss;
        int start = -1, end = -1, curPos = 0, lastPos = -1;
        for(int i = 0; i < ss.length(); ++i) {
            lastPos = binarySearch(lastPos, ss[i], vp);
            if(lastPos == -1) break;
            if(i == 0) start = vp[lastPos].second;
            if(i == ss.length() - 1) end = vp[lastPos].second;
            lastPos = vp[lastPos].second;
        }
         if(end == -1) cout << "Not matched" << endl;
         else cout << "Matched " << start << ' ' << end << endl;
    }
}
