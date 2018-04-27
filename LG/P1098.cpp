#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-26
 *  @Time: 20:40
 *  To change this template use File | Settings | File Templates.
 * 
 */

#define mset(t, x) memset(t,x,sizeof(t))
#define lson index<<1
#define rson (index<<1) +1
#define loop(a, b, c) for(int a=b;a<=c;a++)
#define loop2(a, b, c) for(int a=b;a>=c;a--)
#define loop3(a, b, c) for(int a=b;a<c;a++)
#define loop4(a, b, c) for(int a=b;a>c;a--)
#define maxn 200
#define maxm 10005
int n, m, k;
char ss[maxn];
char ans[maxm];
int P1098() {
    int p1, p2, p3;
    mset(ss, '\0');
    mset(ans, '\0');
    scanf("%d%d%d", &p1, &p2, &p3);
    scanf("%s", ss);
    int index = 0;
    loop3(i, 0, strlen(ss)) {
        if (ss[i] == '-' && i > 0) {
            char last = ss[i - 1];
            char next = ss[i + 1];
            int flag = 0;
            if (last >= 48 && last <= 57 && next <= 57 && next >= 48 && last < next) {
                //填充数字
                flag = 1;
            } else if (last >= 'a' && next <= 'z' && last <= 'z' && next >= 'a' && last < next) {
                //填充字母
                flag = 2;
            }
            if (last == next) {
                //相等
                ans[index++] = ss[i];
                continue;
            } else if (last + 1 == next) {
                //相差一
                continue;
            }
            if (!flag) {
                ans[index++] = ss[i];//两边不一致
            } else {
                if (p3 == 2) {
                    //逆序
                    if (flag == 1) {
                        //逆序填数字，p1参数忽略
                        for (int k = next - 1; k > last; k--) {
                            loop(cnt, 1, p2) {
                                //重复次数
                                if (p1 == 3) {
                                    ans[index++] = '*';
                                } else {
                                    ans[index++] = k;
                                }
                            }
                        }
                    } else {
                        int add = 0;
                        if (p1 == 2) {
                            add = 'a' - 'A';//逆序填大写字母
                        }
                        for (int k = next - 1 - add; k > last - add; k--) {
                            loop(cnt, 1, p2) {
                                //重复次数
                                if (p1 == 3) {
                                    ans[index++] = '*';
                                } else {
                                    ans[index++] = k;
                                }
                            }
                        }
                    }
                } else {
                    //顺序
                    if (flag == 1) {
                        //顺序填数字，p1参数忽略
                        for (int k = last + 1; k < next; k++) {
                            loop(cnt, 1, p2) {
                                //重复次数
                                if (p1 == 3) {
                                    ans[index++] = '*';
                                } else {
                                    ans[index++] = k;
                                }
                            }
                        }
                    } else {
                        int add = 0;
                        if (p1 == 2) {
                            add = 'a' - 'A';//顺序填大写字母
                        }
                        for (int k = last + 1 - add; k < next - add; k++) {
                            loop(cnt, 1, p2) {
                                //重复次数
                                if (p1 == 3) {
                                    ans[index++] = '*';
                                } else {
                                    ans[index++] = k;
                                }
                            }
                        }
                    }
                }
            }
        } else {
            ans[index++] = ss[i];
        }
    }
    printf("%s\n", ans);
    return 0;
}
