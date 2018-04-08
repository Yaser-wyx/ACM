#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-09
 *  @Time: 15:11
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define maxn 1000000

int temp[maxn];//保存要分给别人的糖果
int candy[maxn];
int nums;
int cnt;

void share(int n) {
    cnt = 0;
    bool flag = false;
    while (!flag) {
        int temp2[n];
        for (int i = 0; i < n; i++) {
            temp2[i] = temp[i];//暂存
        }
        for (int i = 0; i < n; i++) {
            int pre = i - 1;//前一个小朋友
            if (pre < 0) {
                pre = n - 1;//防止越界
            }
            candy[i] = candy[i] + temp2[pre] - temp2[i];//更新持有的糖果

            if (candy[i] % 2) {
                //奇数
                candy[i]++;//老师给一个
            }
            temp[i] = candy[i] / 2;//更新下一次要分给别人的糖果
        }
        cnt++;//一轮循环
        //判断
        for (int i = 1; i < n; i++) {
            if (candy[i] != candy[i - 1]) {
                flag = false;//糖果不同
                break;
            } else {
                flag = true;
            }
        }
    }
    nums = candy[0];
}

int main() {
    int n;
    while (~scanf("%i", &n)) {
        if (n == 0)break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &candy[i]);
            temp[i] = candy[i] / 2;
        }
        share(n);
        printf("%d %d\n", cnt, nums);
    }
    return 0;
}