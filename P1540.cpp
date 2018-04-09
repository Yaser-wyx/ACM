#include <bits/stdc++.h>

#define mset(t) memset(t,0,sizeof(t))

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-09
 *  @Time: 11:29
 *  To change this template use File | Settings | File Templates.
 * 
 */
using namespace std;
int n, m;

int P1540() {
    scanf("%d%d", &n, &m);
    queue<int> memory;
    bool now[1000];
    mset(now);
    int temp = 0;
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        scanf("%d", &temp);
        if (!now[temp]) {
            //未放入
            if (memory.size() == n) {
                //容量上限
                int x = memory.front();
                now[x] = 0;
                memory.pop();
            }
            memory.push(temp);
            now[temp] = 1;
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}