#include <bits/stdc++.h>
#define in fstream _file;_file.open(data1,ios::in);if(_file){freopen(data1,"r",stdin);}else{_file.open(data2,ios::in);if(_file)freopen(data2,"r",stdin);}
#define mset(t) memset(t,0,sizeof(t))
#define maxn 14
using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-11
 *  @Time: 10:03
 *  To change this template use File | Settings | File Templates.
 * 
 */

int n;
int dfn_index = 0;
int pre[maxn];
bool vis[maxn];

bool judge(int index) {
    for (int i = 0; i < index; i++) {
        if (abs(pre[i] - pre[index]) == index - i) {
            return 0;
        }
    }
    return 1;
}

void dfs(int index) {
    if (index == n) {
        dfn_index++;
        if (dfn_index <= 3) {
            for (int i = 0; i < n; i++) {
                printf("%d", pre[i] + 1);
                if (i != n) {
                    printf(" ");
                }
            }
            printf("\n");
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            pre[index] = i;
            if (judge(index)) {
                dfs(index + 1);
            }
            vis[i] = 0;
        }
    }
}

int P1219() {
    scanf("%d", &n);
    mset(vis);
    dfs(0);
    printf("%d\n", dfn_index);
    return 0;
}