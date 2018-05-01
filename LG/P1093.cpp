#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-29
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
#define maxn 500
#define maxm 20005
lli l, m, n, minn, maxx, r, q;

struct student {
    int number;
    int grade;
    int chinese;

    bool operator<(const student &student1) const {
        if (grade == student1.grade) {
            if (chinese == student1.chinese) {
                return number < student1.number;
            } else {
                return chinese > student1.chinese;
            }
        } else {
            return grade > student1.grade;
        }
    }

    void set(int number, int chinese, int grade) {
        this->number = number;
        this->chinese = chinese;
        this->grade = grade;

    }
} students[maxn];

int P1093() {
    cin >> n;
    int a, b, c;
    loop(i, 1, n) {
        cin >> a >> b >> c;
        students[i].set(i, a, a + b + c);
    }
    sort(students + 1, students + 1 + n);
    if (n >= 5) {
        n = 5;
    }
    loop(i, 1, n) {
        cout << students[i].number << " " << students[i].grade << endl;
    }
    return 0;
}

 