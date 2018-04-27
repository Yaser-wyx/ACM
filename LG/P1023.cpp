#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-26
 *  @Time: 20:00
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define INF 0xfffffff
#define infinitesimal  -2100000000
#define mset(t, x) memset(t,x,sizeof(t))
#define lson index<<1
#define rson (index<<1) +1
#define loop(a, b, c) for(int a=b;a<=c;a++)
#define loop2(a, b, c) for(int a=b;a>=c;a--)
#define loop3(a, b, c) for(int a=b;a<c;a++)
#define loop4(a, b, c) for(int a=b;a>c;a--)
#define maxn 100005
#define maxm 10005
int n, m, k;

int main() {
    pair<int, int> goods[maxn];
    int matrix[maxn];

    scanf("%d", &n);
    int money, nums, extra;
    int k = 0;
    while (~scanf("%d%d", &money, &nums)) {
        if (money + nums == -2) {
            break;
        }
        goods[k].first = money;
        goods[k++].second = nums;
    }
    scanf("%d", &extra);
    loop3(i, 1, k) {
        int last_money = goods[i - 1].first;
        int last_num = goods[i - 1].second;
        int now_money = goods[i].first;
        int now_num = goods[i].second;
        int per = (last_num - now_num) / (now_money - last_money);//单价销量的减少数量
        matrix[last_money] = last_num;
        loop(start, last_money + 1, now_money) {
            matrix[start] = matrix[start - 1] - per;//对应价格的销量
        }
    }
    int max_money = floor(goods[k - 1].second / extra) + goods[k - 1].first;//最大的销售价格
    loop(start, goods[k - 1].first + 1, max_money) {
        matrix[start] = matrix[start - 1] - extra;
    }
    double maxx = INF, minn = infinitesimal;
    int base = goods[0].first;
    loop(i, base, max_money) {
        if (i == n) {
            continue;
        }
        double a = matrix[n] - matrix[i];
        double b = (i - base) * matrix[i] - (n - base) * matrix[n];
        if (a < 0) {
            maxx = (int) min(maxx, floor(b / a));
        } else if (a == 0) {
            if (b > 0) {
                printf("NO SOLUTION\n");
                return 0;
            }
        } else {
            minn = (int) max(ceil(b / a), minn);
        }
    }
    if (maxx <= 0) {
        printf("%d\n", (int) maxx);
    } else {
        if (minn >= 0) {
            printf("%d\n", (int) minn);
        } else {
            printf("0\n");
        }
    }
    return 0;
}
