#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-11
 *  @Time: 09:30
 *  To change this template use File | Settings | File Templates.
 * 
 */

#define maxn 100005

int pre[maxn];

int P1094() {
    int w, n;

    scanf("%d%d", &w, &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);//读入
    }
    sort(pre, pre + n);//排序
    int *front = pre;//头指针
    int *ed = pre + n - 1;//尾指针
    int cnt = 0;//计数器
    while (front <= ed) {//注意需要=，因为1个也可以是一组
        if (*front + *ed <= w) {//如果二者相加小于w
            front++;
            ed--;
        } else {//如果大于则尾指针前移
            ed--;
        }
        cnt++;//计数
    }
    printf("%d\n", cnt);
    return 0;
}