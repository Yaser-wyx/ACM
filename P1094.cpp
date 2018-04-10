#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-10
 *  @Time: 09:19
 *  To change this template use File | Settings | File Templates.
 * 
 */

#define maxn 1000005
using namespace std;
int n;
struct node {
    int st;
    int ed;
} pairs[maxn];

bool cmp(node a, node b) {//比较
    return a.ed < b.ed;
}

int P1094() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &pairs[i].st, &pairs[i].ed);
    }
    sort(pairs, pairs + n, cmp);//按照结束时间进行排序
    int now = 0;//当前结束的时间
    int cnt = 0;//答案
    for (int i = 0; i < n; i++) {
        if (now < pairs[i].ed && pairs[i].st >= now) {//如果该时间段的结束时间和开始时间都大于前一个时间段的结束时间
            cnt++;
            now = pairs[i].ed;
        }
    }
    printf("%d\n", cnt);
    return 0;
}