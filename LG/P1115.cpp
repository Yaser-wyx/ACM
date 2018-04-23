#include <bits/stdc++.h>
#define infinitesimal  -2100000000

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  WXY
 *  @Date: 2018-04-20
 *  @Time: 20:52
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define mset(t, x) memset(t,x,sizeof(t))
#define loop(a, b, c) for(int a=b;a<=c;a++)
#define maxn 200010
int n, m;
int pre[maxn];
int indexes[maxn];

int main() {
    scanf("%d", &n);
    mset(pre, 0);
    int temp;
    int min_num;
    scanf("%d", &min_num);
    pre[1] = min_num;
    int index = 0;
    loop(i, 2, n) {
        scanf("%d", &temp);
        pre[i] = pre[i - 1] + temp;
        indexes[i] = index;
        if (min_num > pre[i]) {
            index = i;
            min_num = pre[i];
        }

    }
    int ans = infinitesimal;
    loop(i, 1, n) {
        ans = max(ans, pre[i] - pre[indexes[i]]);
    }

    printf("%d\n", ans);

    return 0;
}