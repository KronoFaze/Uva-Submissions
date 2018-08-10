#include <bits/stdc++.h>
using namespace std;

int ar[505][505];

int binarySearch(int x1, int y1, int x2, int y2, int target) {
    int ret = -1;
    while(x1 <= x2 && y1 <= y2) {
        int x = (x1 + x2) >> 1;
        int y = (y1 + y2) >> 1;
        if(ar[x][y] <= target) {
            ret = x;
            x1 = x + 1;
            y1 = y + 1;
        } else if(ar[x][y] > target) {
            x2 = x - 1;
            y2 = y - 1;
        }
    }
    return ret;
}

int main(void)
{
    int n, m;
    while(scanf("%d %d", &n, &m)) {
        if(n == 0) return 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                scanf("%d", &ar[i][j]);
        int q;
        scanf("%d", &q);
        while(q--) {
            int l, r;
            scanf("%d %d", &l, &r);
            int ans = 0;
            for(int i = 0; i < n; ++i) {
                int j = lower_bound(ar[i], ar[i] + m, l) - ar[i];
                if(j != m) {
                    int offset = min(n - i, m - j) - 1;
                    int newOffset = binarySearch(i, j, i + offset, j + offset, r) - i;
                    ans = max(ans, newOffset + 1);
                }
            }
            printf("%d\n", ans);
        }
        printf("-\n");
    }

}
