#include <bits/stdc++.h>
using namespace std;

long long distance(int x1, int y1, int x2, int y2) {
    return 1LL * (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main(void) {
    int n, tc = 0;
    while(~scanf("%d", &n)) {
        if(n == 0) return 0;
        printf("Case %d:\n", ++tc);
        vector <pair <int, int> > v;
        for(int i = 0; i < n; ++i) {
            int x, y;
            scanf("%d %d", &x, &y);
            v.push_back(make_pair(x, y));
        }
        int ax, ay, bx, by, q;
        scanf("%d %d %d %d %d", &ax, &ay, &bx, &by, &q);
        vector <long long> dis1, dis2;
        for(int i = 0; i < n; ++i) {
            dis1.push_back(distance(v[i].first, v[i].second, ax, ay));
            dis2.push_back(distance(v[i].first, v[i].second, bx, by));
        }
        sort(dis1.begin(), dis1.end());
        sort(dis2.begin(), dis2.end());
        while(q--) {
            int ans = n;
            long long r1, r2;
            scanf("%lld %lld", &r1, &r2);
            int cnt1 = upper_bound(dis1.begin(), dis1.end(), r1 * r1) - dis1.begin();
            int cnt2 = upper_bound(dis2.begin(), dis2.end(), r2 * r2) - dis2.begin();
            if(cnt1 != dis1.size()) ans -= cnt1;
            if(cnt2 != dis2.size()) ans -= cnt2;
            printf("%d\n", max(ans, 0));
        }
    }
}
