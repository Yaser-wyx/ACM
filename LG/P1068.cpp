#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-26
 *  @Time: 21:34
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
#define maxn 5005
#define maxm 10005
int n;
double m;

struct people {
    int No;
    int grade;

    bool operator<(const people &rhs) const {
        if (grade == rhs.grade) {
            return No < rhs.No;
        }
        return grade > rhs.grade;
    }
} peoples[maxn];


int P1068() {
    scanf("%d%lf", &n, &m);
    loop(i, 1, n) {
        scanf("%d%d", &peoples[i].No, &peoples[i].grade);
    }
    sort(peoples + 1, peoples + n + 1);
    int last = floor(m * 1.5);
    int grade = peoples[last].grade;
    int nums = last;
    loop(i, last + 1, n) {
        if (peoples[i].grade == grade) {
            nums++;
        } else {
            break;
        }
    }
    printf("%d %d\n", grade, nums);
    loop(i, 1, nums) {
        printf("%d %d\n", peoples[i].No, peoples[i].grade);
    }
    return 0;
}

 