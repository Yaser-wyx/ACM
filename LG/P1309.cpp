#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-29
 *  @Time: 15:13
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
#define maxn 200005
#define maxm 20005
lli l, m, n, minn, maxx, r, q;

struct player {
    int Number;
    int strength;
    int grade;

    bool operator<(const player &player2) const {
        if (grade == player2.grade) {
            return Number < player2.Number;
        }
        return grade > player2.grade;
    }
} players[maxn];
player loser[maxn >> 1];
player winner[maxn >> 1];
int P1309() {
    cin >> n >> r >> q;
    n <<= 1;
    loop(i, 1, n) {
        cin >> players[i].grade;
        players[i].Number = i;
    }
    loop(i, 1, n) {
        cin >> players[i].strength;
    }
    sort(players + 1, players + 1 + n);

    loop(k, 1, r) {
        int w = 0, l = 0;
        for (int i = 2; i <= n; i += 2) {
            if (players[i - 1].strength > players[i].strength) {
                players[i - 1].grade++;
                winner[w++] = players[i - 1];
                loser[l++] = players[i];
            } else {
                players[i].grade++;
                winner[w++] = players[i];
                loser[l++] = players[i - 1];
            }
        }
        w = 0;
        l = 0;
        loop(i, 1, n) {
            if (w >= (n >> 1)) {
                players[i] = loser[l++];
            } else if (l >= (n >> 1)) {
                players[i] = winner[w++];
            } else if (winner[w] < loser[l]) {
                players[i] = winner[w++];
            } else {
                players[i] = loser[l++];
            }
        }
    }

    cout << players[q].Number;
    return 0;
}
