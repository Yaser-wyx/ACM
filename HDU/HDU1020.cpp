#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-02-28
 *  @Time: 7:58
 *  To change this template use File | Settings | File Templates.
 * 
 */

int HDU1020() {
    int n;
    scanf("%d", &n);
    char c[10100];
    memset(c, '\0', sizeof(c));
    while (n--) {
        scanf("%s", c);
        auto len = strlen(c);
        char last = c[0];//保存上一个字符
        int num = 1;//计数
        string ans = "";
        for (int i = 1; i < len; i++) {
            if (c[i] == last) {//如果一样就加1
                num++;
            } else {
                if (num == 1) {
                    ans += last;
                } else {
                    ans += to_string(num) + last;
                }
                num = 1;
                last = c[i];
            }
        }
        //因为最后一组字符统计完还没有加入到答案中
        if (num == 1) {
            ans += last;
        } else {
            ans += to_string(num) + last;
        }
        cout << ans << endl;

    }
    return 0;
}