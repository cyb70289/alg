/* https://www.geeksforgeeks.org/check-possible-make-given-matrix-increasing-matrix-not */

#include <iostream>

using namespace std;

int inc_mtx(int m[4][4])
{
    if (m[0][0] == -1)
        m[0][0] = 1;

    for (int i = 1; i < 4; i++) {
        if (m[0][i] == -1)
            m[0][i] = m[0][i-1];
        if (m[i][0] == -1)
            m[i][0] = m[i-1][0];
    }

    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            int v = max(m[i-1][j], m[i][j-1]);
            if (m[i][j] == -1)
                m[i][j] = v;
            else if (m[i][j] < v)
                return -1;
        }
    }

    return 0;
}

int main(void)
{
    int m[4][4] = {
        {  1,  2,  2,  3 },
        {  1, -1,  7, -1 },
        {  6, -1, -1, -1 },
        { -1, -1, -1, -1 },
    };

    int r = inc_mtx(m);
    if (r == 0) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++)
                cout << m[i][j] << ' ';
            cout << endl;
        }
    } else {
        cout << -1;
    }

    return 0;
}
