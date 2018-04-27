#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-27
 *  @Time: 10:58
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
#define maxn 100005
#define maxm 10005
lli n, b, k;
struct chocolate {
    lli price;
    lli cows;
} chocolates[maxn];

bool cmp(const chocolate &c1, const chocolate &c2) {
    return c1.price < c2.price;

}

int P2983() {
    cin >> n >> b;
    loop3(i, 0, n) {
        cin >> chocolates[i].price >> chocolates[i].cows;
    }
    sort(chocolates, chocolates + n, cmp);
    lli nums = 0;
    lli money = 0;
    loop3(i, 0, n) {
        lli temp = money + chocolates[i].price * chocolates[i].cows;
        if (temp >= b) {
            lli nn = floor((double) (b - money) / (double) chocolates[i].price);
            nums += nn;
            break;
        } else {
            nums += chocolates[i].cows;
            money = temp;
        }
    }
    cout << nums;
    return 0;
}
