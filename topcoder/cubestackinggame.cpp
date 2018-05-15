/* https://community.topcoder.com/stat?c=problem_statement&pm=14845&rd=17103
 *
 * You recently designed the Cube Stacking Game. This is a single-player puzzle.
 * All you need to play the game is a collection of cubes, as described below.
 *
 * You have n cubes. The cubes are numbered from 0 to n-1. Each face of each
 * cube has a single color. There are n+1 colors. One of the colors is white
 * and has number 0. The remaining colors have numbers 1 to n.
 *
 * Each cube has exactly two white faces, and these are always two opposite
 * faces. Let's number the remaining faces on each cube 1, 2, 3, 4 in adjacent
 * order. (That is, face 1 is adjacent to 2, 2 to 3, 3 to 4, and 4 to 1.)
 * For each cube, you are given the colors of these four faces: on cube i these
 * faces have colors c1[i], c2[i], c3[i] and c4[i], in order. Remember that
 * these faces are never white.
 *
 * You want to build a single stack of cubes with cube 0 on the bottom, cube 1
 * on top of cube 0, and so on. (I.e., you have to use the cubes in the given
 * order, starting with 0, and you are not allowed to skip any cube.)
 *
 * The cubes have to be aligned to form a single stack with four vertical sides.
 * You may rotate the cubes arbitrarily but you must place them onto the stack
 * in such a way that the top and bottom face of each cube will be white. On
 * each of the four sides of the stack each color can only appear at most once.
 * Calculate and return the maximum height of a valid stack that can be built
 * out of the given cubes.
 *
 * Constraints
 * -	n will be between 2 and 8, inclusive.
 * -	Each of c1, c2, c3, c4 will contain exactly n elements.
 * -	Each element of c1 will be between 1 and n, inclusive.
 * -	Each element of c2 will be between 1 and n, inclusive.
 * -	Each element of c3 will be between 1 and n, inclusive.
 * -	Each element of c4 will be between 1 and n, inclusive.
 */

#include <iostream>

using namespace std;

const int N = 8;
const int C[4][N] = {
    {5, 2, 6, 4, 5, 5, 8, 8},
    {8, 3, 2, 8, 7, 8, 1, 4},
    {3, 2, 8, 7, 1, 7, 2, 6},
    {6, 7, 8, 6, 2, 1, 2, 3},
};

int canstack(int h, int c_all[4][N], const int c[4][N], int dir)
{
    int mirror = dir & 1;
    dir >>= 1;

    for (int i = 0; i < 4; i++)
        c_all[i][h] = c[i][h];
    while (dir--) {
        int tmp = c_all[0][h];
        c_all[0][h] = c_all[1][h];
        c_all[1][h] = c_all[2][h];
        c_all[2][h] = c_all[3][h];
        c_all[3][h] = tmp;
    }
    if (mirror)
        swap(c_all[0][h], c_all[2][h]);

    for (int i = 0; i < h; i++)
        for (int j = 0; j < 4; j++)
            if (c_all[j][i] == c_all[j][h])
                return 0;

    return 1;
}

int maxheight1(int h, int n, int c_all[4][N], const int c[4][N])
{
    if (h >= n)
        return 0;

    int maxh = 0;
    for (int i = 0; i < 8; i++)
        if (canstack(h, c_all, c, i))
            maxh = max(maxh, 1+maxheight1(h+1, n, c_all, c));

    return maxh;
}

int maxheight(int n, const int c[4][N])
{
    int c_all[4][N];

    for (int i = 0; i < 4; i++)
        c_all[i][0] = c[i][0];

    return 1 + maxheight1(1, n, c_all, c);
}

int main(void)
{
    cout << maxheight(N, C) << endl;

    return 0;
}
