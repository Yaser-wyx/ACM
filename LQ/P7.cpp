#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-27
 *  @Time: 15:18
 *  To change this template use File | Settings | File Templates.
 * 
 */

int day(int y, int m, int d) {
    if (m == 1 || m == 2) {
        y--;
        m += 12;
    }
    return (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
}

int p7() {
    string weekday[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int y, m, d;
    scanf("%d%d%d", &y, &m, &d);
    int ans = day(y, m, d);
    cout << weekday[ans] << endl;
    return 0;
}