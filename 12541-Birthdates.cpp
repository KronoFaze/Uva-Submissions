#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    scanf("%d", &n);
    string small, big;
    int mn = INT_MAX, mx = INT_MIN;
    while(n--) {
        char s[20];
        int d, m, y;
        scanf("%s %d %d %d", s, &d, &m, &y);
        int age = d + 30 * m + 365 * y;
        if(age < mn) {
            mn = age;
            small = s;
        }
        if(age > mx) {
            mx = age;
            big = s;
        }
    }
    printf("%s\n%s\n", big.c_str(), small.c_str());
}
