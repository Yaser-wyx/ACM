#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  WXY
 *  @Date: 2018-04-12
 *  @Time: 09:55
 *  To change this template use File | Settings | File Templates.
 * 
 */#define mset(t) memset(t,0,sizeof(t))
#define maxn 200010
int n;
int nums[maxn];
int steps[maxn];//步数
int degree[maxn];//入度
int flag[maxn];//染色标记

int P2661() {
    mset(steps);
    mset(degree);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &nums[i]);
        degree[nums[i]]++;
    }
    int ans = n;
    for (int index = 1; index <= n; index++) {//遍历一遍图
        int next = nums[index];//下一个点
        if (degree[index] && steps[index] == 0) {//如果入度不为0或者当前节点未访问过
            flag[index] = index;//给当前节点染色
            int temp = index;
            while (steps[next] == 0) {//遍历图
                flag[next] = index;//染色
                steps[next] = steps[temp] + 1;
                temp = next;
                next = nums[temp];
            }
            int st = steps[temp] + 1 - steps[next];
            if (flag[temp] == flag[next] && flag[next] == index) {//如果在同一部分中
                ans = min(ans, st);//选取较小值
            }

        }
    }
    printf("%d\n", ans);
    return 0;
}