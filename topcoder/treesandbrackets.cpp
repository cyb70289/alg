/* https://community.topcoder.com/stat?c=problem_statement&pm=14836
 *
 * This problem is about rooted trees in which the order of children matters.
 * This type of trees is easily encoded using correct bracket sequences. The
 * code of a tree rooted at r is constructed as follows:
 *
 * Write down the opening bracket '('.
 * For each child c of r, in order, write down the code of the subtree rooted
 * at c.
 * Write down the closing bracket ')'.
 *
 * For example, the code of a three-vertex tree in which the root has two
 * children is "(()())". You are given the Strings t1 and t2 that represent
 * two rooted trees using the encoding defined above. You want to transform
 * t1 into t2.
 *
 * The only operation you are allowed to perform is to remove a leaf from t1.
 * (A leaf is a vertex with no children.) Note that removing the child of a
 * parent does not change the relative order of the other children of that
 * same parent.
 *
 * Return "Possible" if there is a sequence of zero or more operations that
 * transforms t1 into t2. Otherwise, return "Impossible".
 *
 * Constraints
 * -	t1 and t2 will contain between 2 and 100 characters, inclusive.
 * -	Each character in t1 and t2 will be either '(' or ')'.
 * -	Both t1 and t2 will represent a correct tree.
 */

#include <iostream>
#include <cstring>

using namespace std;

int next_bracket(const char *t, int &start, int &end, int len)
{
    if (end >= len-1)
        return 0;

    start = end+1;
    if (t[start] != '(')
        return 0;

    int cnt = 1;
    end = start;
    while (cnt) {
        if (t[++end] == '(')
            cnt++;
        else
            cnt--;
    }

    return 1;
}

int is_sub(const char *t1, int t1_len, const char *t2, int t2_len)
{
    if (t1_len < t2_len)
        return 0;
    if (t2_len == 2)
        return t1_len >= 2;

    int t1_start, t1_end = 0;
    int t2_start, t2_end = 0;

    while (next_bracket(t2, t2_start, t2_end, t2_len)) {
        int ok = 0;
        const char *_t2 = t2 + t2_start;
        int _t2_len = t2_end - t2_start + 1;

        while (next_bracket(t1, t1_start, t1_end, t1_len)) {
            const char *_t1 = t1 + t1_start;
            int _t1_len = t1_end - t1_start + 1;

            if (is_sub(_t1, _t1_len, _t2, _t2_len)) {
                ok = 1;
                break;
            }
        }

        if (!ok)
            return 0;
    }

    return 1;
}

int main(void)
{
    const char *t1 = "((())((())())())";
    const char *t2 = "(()(())())";

    cout << is_sub(t1, strlen(t1), t2, strlen(t2)) << endl;

    return 0;
}
