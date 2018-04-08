#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-08
 *  @Time: 17:17
 *  To change this template use File | Settings | File Templates.
 * 
 */


int x, m, k;

struct t_shirt {
    double data = 0;
    int index;

    bool operator<(const t_shirt &rhs) const {
        return data > rhs.data;
    }
};


int main() {
    while (~scanf("%d%d%d", &x, &m, &k)) {
        t_shirt shirts[m];
        for (int i = 0; i < x; i++) {
            double temp = 0;
            for (int j = 0; j < m; j++) {
                scanf("%lf", &temp);
                shirts[j].data += temp;
                shirts[j].index = j + 1;
            }
        }
        sort(shirts, shirts + m);
        int ans[k];
        for (int i = 0; i < k; i++) {
            ans[i] = shirts[i].index;
        }
        sort(ans, ans + k, greater<int>());
        for (int i = 0; i < k; i++) {
            printf("%d", ans[i]);
            if (i != k - 1) {
                printf(" ");
            }
        }
        printf("\n");

    }
    return 0;
}