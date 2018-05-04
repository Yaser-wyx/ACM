#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-03
 *  @Time: 15:31
 *  To change this template use File | Settings | File Templates.
 * 
 */

#define mset(t, x) memset(t,x,sizeof(t))
#define lson index<<1
#define rson (index<<1) +1
#define loop(a, b, c) for(register int a=b;a<=c;a++)
#define loop2(a, b, c) for(int a=b;a>=c;a--)
#define loop3(a, b, c) for(int a=b;a<c;a++)
#define loop4(a, b, c) for(int a=b;a>c;a--)
#define maxn 2550
int n, m, s, t;

int main() {
    cin >> m >> s >> t;
    int run, cnt;
    run = 0;
    cnt = t;
    bool flag = 0;
    while (cnt > 0 && s > run) {
        if (m >= 10) {
            //闪烁
            run += 60;
            m -= 10;
            cnt--;
            if (run >= s) {
                flag = 1;
                break;
            }
        } else {
            //进行判断是休息还是跑步
            int rest = ceil(double(10 - m) / 4.0) + 1; //获取需要多久才能进行下一次闪烁
            //判断休息加上闪烁的时间能否跑出去
            if (rest <= cnt) {
                if (rest * 17 + run >= s) {
                    //在这段时间里如果可以跑出去
                    cnt -= ceil(double(s - run) / 17.0);
                    flag = 1;
                    break;
                } else {
                    //在此时间里面跑不出去
                    //休息然后闪烁
                    cnt -= rest;
                    m += 4 * (rest - 1);
                    run += 60;
                    m -= 10;
                    if (run >= s) {
                        flag = 1;
                        break;
                    }
                }
            } else {
                //不可以闪烁，只能选择跑步
                if (cnt * 17 + run < s) {
                    //逃不出去
                    flag = 0;
                    run += cnt * 17;
                    break;
                } else {
                    //可以逃出去
                    flag = 1;
                    cnt -= ceil(double(s - run) / 17.0);
                    break;
                }
            }

        }
    }
    if (flag) {
        //逃走了
        cout << "Yes\n" << (t - cnt) << endl;
    } else {
        cout << "No\n" << run << endl;
    }
    return 0;
}
