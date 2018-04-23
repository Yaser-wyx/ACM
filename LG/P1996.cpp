#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  WXY
 *  @Date: 2018-04-20
 *  @Time: 20:15
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define mset(t, x) memset(t,x,sizeof(t))
#define loop(a, b, c) for(int a=b;a<=c;a++)
#define maxn 3015
int n, m;

int P1996() {
    scanf("%d%d", &n, &m);
    queue<int> queue1;
    loop(i, 1, n) {
        queue1.push(i);
    }
    queue<int> temp;
    queue<int> ans;
    int cnt = 1;
    while (ans.size() < n) {
        while (!queue1.empty()) {
            int num = queue1.front();
            queue1.pop();
            if (cnt != m) {
                cnt++;
                temp.push(num);
            } else {
                cnt = 1;
                ans.push(num);
            }
        }
        while (!temp.empty()) {
            int num = temp.front();
            temp.pop();
            queue1.push(num);
        }
    }
    while (!ans.empty()) {
        int num = ans.front();
        ans.pop();
        printf("%d", num);

        if (!ans.empty()) {
            printf(" ");
        }
    }
    return 0;
}