#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-02-27
 *  @Time: 20:45
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define maxn 4000

int x;
char o1[maxn];//进站顺序
char o2[maxn];//出站顺序
bool nums[maxn];//解决方案，false代表出站，true代表进站


bool judge() {
    memset(nums, false, sizeof(nums));//初始化
    stack<char> stack1;
    int index1 = 0;//o1索引
    int index2 = 0;//o2索引
    x = 0;//ans索引
    while (index2 < x) {//不断循环，直到火车全部出站
        if (stack1.empty() || o2[index2] != stack1.top()) {//如果栈为空或栈顶元素与下一个出栈的元素不一致，则进栈
            if (index1 == x) {//如果已经没有火车可以入站了，但栈顶元素不是下一个应该出栈的则表示没有解决方案
                return false;
            }
            stack1.push(o1[index1++]);
            nums[x++] = true;
        } else {//栈顶元素与下一个出栈的元素一致，则出栈
            stack1.pop();
            nums[x++] = false;
            index2++;
        }
    }
    return true;
}

int HDU1022() {

    while (~scanf("%d", &x)) {
        scanf("%s", o1);
        scanf("%s", o2);
        if (judge()) {
            printf("Yes.\n");
            for (int i = 0; i < x; i++) {
                if (nums[i]) {
                    printf("in\n");
                } else {
                    printf("out\n");
                }
            }
            printf("FINISH\n");
        } else {
            printf("No.\nFINISH\n");
        }
    }
    return 0;
}