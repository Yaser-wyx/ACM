#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-26
 *  @Time: 15:42
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define maxn 10

int p6() {

    bool vis[10] = {false};
    for (int i = 1; i < maxn; i++) {//祥
        vis[i] = true;
        for (int j = 0; j < maxn; j++) {//瑞
            if (!vis[j]) {
                vis[j] = true;
                for (int k = 0; k < maxn; k++) {//生
                    if (!vis[k]) {
                        vis[k] = true;
                        for (int l = 0; l < maxn; l++) {//辉
                            if (!vis[l]) {
                                vis[l] = true;
                                //第二个表达式
                                for (int a = 1; a < maxn; a++) {//三
                                    if (!vis[a]) {
                                        vis[a] = true;
                                        for (int b = 0; b < maxn; b++) {//羊
                                            if (!vis[b]) {
                                                vis[b] = true;
                                                for (int c = 0; c < maxn; c++) {//献
                                                    if (!vis[c]) {
                                                        vis[c] = true;
                                                        for (int d = 0; d < maxn; d++) {//气
                                                            if (!vis[d]) {
                                                                int x = i * 1000 + j * 100 + k * 10 + l;
                                                                int y = a * 1000 + b * 100 + c * 10 + j;
                                                                int w = a * 10000 + b * 1000 + k * 100 + j * 10 + d;
                                                                if (x + y == w) {
                                                                    printf("%d %d %d", x, y, w);
                                                                    return 0;
                                                                }
                                                            }
                                                        }
                                                        vis[c] = false;
                                                    }
                                                }
                                                vis[b] = false;
                                            }
                                        }
                                        vis[a] = false;
                                    }
                                }
                                vis[l] = false;
                            }
                        }
                        vis[k] = false;
                    }
                }
                vis[j] = false;
            }

        }
        vis[i] = false;
    }
    return 0;
}