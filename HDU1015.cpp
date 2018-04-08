#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-02-26
 *  @Time: 10:58
 *  To change this template use File | Settings | File Templates.
 * 
 */
namespace hdu1015 {
    int target;//给定的目标值
    char c[27];//给的字符串
    bool vis[27];//该字母是否被使用过了
    size_t len;//数组长度
    bool flag;//是否已经找到解

    bool cmp(char c1, char c2) {
        return c1 > c2;
    }

    bool judge(char *ans) {//判断是否等于target
        long sum = 0;
        for (int i = 0; i < 5; i++) {
            int temp = ans[i] - 64;
            if (i % 2) {//判断正负符号
                //奇数为负
                sum -= pow(temp, i + 1);
            } else {
                //偶数为正
                sum += pow(temp, i + 1);
            }
        }
        return sum == target;
    }


    void dfs(int index, char ans[10]) {
        if (index == 5) {
            if (judge(ans)) {
                flag = true;
            }
            return;
        }
        for (int i = 0; i < len && !flag; i++) {
            int temp = c[i] - 64;
            if (!vis[temp]) {
                //没有访问过
                vis[temp] = true;
                ans[index] = c[i];
                dfs(index + 1, ans);
                vis[temp] = false;//回溯处理
            }

        }
    }
}
using namespace hdu1015;

int HDU1015() {
    memset(c, '\0', sizeof(c));
    while (~scanf("%d%s", &target, c)) {
        string str = c;
        if (target == 0 && str == "END")break;
        len = strlen(c);
        sort(c, c + len, cmp);//逆序
        char ans[10];
        memset(ans, '\0', sizeof(ans));
        memset(vis, false, sizeof(vis));
        flag = false;
        dfs(0, ans);
        if (flag) {
            printf("%s\n", ans);
        } else {
            printf("no solution\n");
        }
    }
    return 0;
}