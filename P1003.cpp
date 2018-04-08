#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-02
 *  @Time: 14:51
 *  To change this template use File | Settings | File Templates.
 * 
 */

#define maxn
int n;

struct node {
    int left;
    int right;
    int up;
    int down;

    node(int x, int y, int g, int k) {
        //x,y为左下角
        left = x;
        right = x + g;
        up = y + k;
        down = y;
    }

    bool in(int x, int y) {
        return x >= left && x <= right && y >= down && y <= up;
    }


};

int main() {
    scanf("%d", &n);
    stack<node> stack1;
    int a, b, g, k;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &a, &b, &g, &k);
        node node1(a, b, g, k);
        stack1.push(node1);
    }
    int x, y;
    scanf("%d%d", &x, &y);
    while (!stack1.empty()) {
        node node1 = stack1.top();
        stack1.pop();
        if (node1.in(x, y)) {
            printf("%d\n", n);
            return 0;
        }
        n--;
    }

    printf("%d\n", -1);
    return 0;
}