#include <bits/stdc++.h>
using namespace std;
const int mx = 100005;
bool sieve[mx + 5];

void pre(void) {
    for(int i = 4; i <= mx; i += 2) sieve[i] = 1;
    for(int i = 3; i * i <= mx; i += 2) {
        if(!sieve[i]) {
            for(int j = i * i; j <= mx; j += i + i) {
                sieve[j] = 1;
            }
        }
    }
}

int main(void) {
    pre();
    string num;
    while(cin >> num) {
        if(num.length() == 1 && num[0] == '0') return 0;
        int ans = 0;
        for(int i = 0; i < num.length(); ++i) {
            int cur = 0;
            for(int j = i; j < num.length(); ++j) {
                cur *= 10;
                cur += (num[j] - '0');
                if(cur > 100000) break;
                if(!sieve[cur] && cur > ans) ans = cur;
            }
        }
        printf("%d\n", ans);
    }
}
