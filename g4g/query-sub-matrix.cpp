/* https://www.geeksforgeeks.org/queries-number-binary-sub-matrices-given-size */

#include <iostream>
#include <vector>

using namespace std;

const int M = 5, N = 4;
const int m[M][N] = {
    { 0, 0, 1, 1 },
    { 0, 0, 1, 0 },
    { 0, 1, 1, 1 },
    { 1, 1, 1, 1 },
    { 0, 1, 1, 1 },
};

int can_increase(int r, int c, int s, int b)
{
    if (r+s > M || c+s > N)
        return 0;
    for (int i = r; i <= r+s-1; i++)
        if (m[i][c+s-1] != b)
            return 0;
    for (int i = c; i < c+s-1; i++)
        if (m[r+s-1][i] != b)
            return 0;
    return 1;
}

int count_sub(int a, int b)
{
    /* 1x1 */
    vector<pair<int,int>> v;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if (m[i][j] == b)
                v.push_back(make_pair(i, j));

    for (int s = 2; s <= a; s++) {
        vector<pair<int,int>> v2;
        for (int i = 0; i < v.size(); i++)
            if (can_increase(v[i].first, v[i].second, s, b))
                v2.push_back(v[i]);
        v = v2;
    }

    return v.size();
}

int main(void)
{
    cout << count_sub(2, 1) << endl;
    cout << count_sub(2, 0) << endl;
    cout << count_sub(3, 1) << endl;

    return 0;
}
