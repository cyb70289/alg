/* https://community.topcoder.com/stat?c=problem_statement&pm=14847
 *
 * Deadfish+ is a programming language with only 4 commands. All commands modify
 * a single register. The register is initially set to zero, and during the
 * execution of a program it can store an arbitrarily large integer value.
 * The commands are:
 *
 * "i" - increment the value,
 * "d" - decrement the value,
 * "s" - square the value, and
 * "p" - sort the digits of the number into non-increasing order
 *       (i.e., biggest to smallest).
 *
 * For example, "p" changes 4070 to 7400, and it changes -4070 to -7400
 * (the minus sign is preserved).
 *
 * You are given an int N. Return the minimal number of commands necessary to
 * make the register hold the number N.
 *
 * Constraints
 *  - N will be between 1 and 200,000, inclusive.
 */

#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 200000;
const int N_SQRT = 447;

int min_cmds[N+1];

static int get_min_cmds1(int n, queue<int> &q)
{
    int cur = q.front();
    int m = min_cmds[cur];
    q.pop();

    if (cur-1 >= 0 && min_cmds[cur-1] == 0) {
        min_cmds[cur-1] = m+1;
        if (n == cur-1)
            return m+1;
        q.push(cur-1);
    }

    if (cur+1 <= N && min_cmds[cur+1] == 0) {
        min_cmds[cur+1] = m+1;
        if (n == cur+1)
            return m+1;
        q.push(cur+1);
    }

    if (cur <= N_SQRT && min_cmds[cur*cur] == 0) {
        min_cmds[cur*cur] = m+1;
        if (n == cur*cur)
            return m+1;
        q.push(cur*cur);
    }

    int buf[10], len=0, cur2=cur, p = 0;
    while (cur2) {
        buf[len++] = cur2 % 10;
        cur2 /= 10;
    }
    sort(buf, buf+len, std::greater<int>());
    for (int i = 0; i < len; i++) {
        p *= 10;
        p += buf[i];
    }
    if (p <= N && min_cmds[p] == 0) {
        min_cmds[p] = m+1;
        if (p == n)
            return m+1;
        q.push(p);
    }

    return 0;
}

static int get_min_cmds(int n)
{
    queue<int> q;

    q.push(1);
    while (!q.empty()) {
        int m = get_min_cmds1(n, q);
        if (m)
            return m;
    }

    return -1;
}

int main(void)
{
    min_cmds[1] = 1;

    cout << get_min_cmds(200000) << endl;

    return 0;
}
