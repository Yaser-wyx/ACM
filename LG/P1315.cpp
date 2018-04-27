    #include <bits/stdc++.h>

    using namespace std;
    typedef long long int lli;
    /**
     *  Created with IntelliJ Clion.
     *  @author  wanyu
     *  @Date: 2018-04-25
     *  @Time: 09:01
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
    #define maxn 1005
    #define maxm 10005
    int n, m, k;
    int influence[maxn];//从第i-1个点加速，会影响到第几站
    int times[maxn];//到达当前站点所需时间
    int go[maxn];//汽车最早出发的时间
    int arrive[maxn];//汽车到达的时间
    int leave[maxn];//该站下车人数
    struct people {
        int time;
        int from;
        int to;
    } peoples[maxm];

    int P1315() {
        mset(influence, 0);
        mset(times, 0);
        mset(go, 0);
        mset(arrive, 0);
        mset(leave, 0);

        scanf("%d%d%d", &n, &m, &k);
        loop(i, 2, n) {
            scanf("%d", &times[i]);
        }
        int t, a, b;
        loop(i, 1, m) {
            scanf("%d%d%d", &t, &a, &b);
            peoples[i].time = t;
            peoples[i].from = a;
            peoples[i].to = b;
            go[a] = max(go[a], t);
            leave[b]++;//离站人数
        }
        loop(i, 1, n) {
            arrive[i] = max(arrive[i - 1], go[i - 1]) + times[i];//每一站到达时间
            leave[i] += leave[i - 1];
        }
        int ans = 0;
        loop(i, 1, m) {
            ans += (arrive[peoples[i].to] - peoples[i].time);//不加速的总时间
        }
        int temp = 0;
        while (k--) {
            //每使用一个加速器
            influence[n] = influence[n - 1] = n;
            loop2(i, n - 2, 1) {
                if (arrive[i + 1] <= go[i + 1]) {
                    //下一个点需要等待
                    influence[i] = i + 1;//最多影响到下一个点
                } else {
                    //下一个点无需等待
                    influence[i] = influence[i + 1];//可以一直影响下去
                }
            }
            int mx = 0;
            int index = 0;
            //获取最多可以影响到的人数
            loop3(i, 1, n) {
                int p = leave[influence[i]] - leave[i];
                if (p > mx && times[i + 1] > 0) {
                    index = i + 1;
                    mx = p;
                }
            }
            times[index]--;//到站时间减少
            temp += mx;
            loop(i, index, n) {
                arrive[i] = max(arrive[i - 1], go[i - 1]) + times[i];//更新每一站到达时间
            }
        }


        printf("%d\n", ans - temp);
        return 0;
    }
