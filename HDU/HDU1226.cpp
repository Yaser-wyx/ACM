#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-20
 *  @Time: 20:26
 *  To change this template use File | Settings | File Templates.
 * 
 */

#define no "give me the bomb please\n"
int n, m, x;
vector<int> pre;
bool flag;
bool vis[5050];

struct node {
    int len = 0;
    int ans[550] = {0};

    void add(int a) {
        ans[len++] = a;
    }

    void del() {
        len--;
    }

    node(int n) { add(n); }
};

int judge(node node1) {
    int temp = 0;
    for (int i = 0; i < node1.len; i++) {
        temp = (temp * x + node1.ans[i]) % n;
    }
    return temp;
}

void print(node node1) {
    for (int i = 0; i < node1.len; i++) {
        printf("%X", node1.ans[i]);
    }
    putchar('\n');
}

void bfs() {
    flag = false;
    queue<node> queue1;
    for (int i = 0; i < pre.size(); i++) {//添加节点
        int index = pre[i];
        if (index == 0) {
            continue;//0不放在首位
        }
        node temp(index);
        int res = judge(temp);
        if (!res) {
            //已经找到了
            flag = true;
            print(temp);
            return;
        }
        if (!vis[res]) {
            vis[res] = true;
            queue1.push(temp);
        }
    }
    while (!queue1.empty()) {
        node temp = queue1.front();
        queue1.pop();
        for (int i = 0; i < pre.size(); i++) {
            int index = pre[i];
            temp.add(index);
            int res = judge(temp);
            if (!res) {
                //找到了
                flag = true;
                print(temp);
                return;
            }
            if (!vis[res] && temp.len < 500) {//注意位数不可超过500
                vis[res] = true;
                queue1.push(temp);
            }
            temp.del();
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(vis, false, sizeof(vis));
        pre.clear();
        scanf("%d%d%d", &n, &x, &m);
        bool zero = false;
        for (int i = 0; i < m; i++) {
            int k;
            scanf("%x", &k);
            if (k == 0) {
                zero = true;
            }
            pre.push_back(k);//读取数据
        }
        sort(pre.begin(), pre.end());//注意排序
        //对0进行特判
        if (!n) {
            if (zero) {
                //如果有0
                printf("0\n");
            } else {
                //没有
                printf(no);
            }
            continue;
        }
        bfs();
        if (!flag) {
            //还没有输出过
            printf(no);
        }
    }
    return 0;
}