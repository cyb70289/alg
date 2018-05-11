/* https://community.topcoder.com/stat?c=problem_statement&pm=14891
 * Consider the set of integers between 1 and n, inclusive, and two positive
 * integers c and k. You want to build an ordered list of k pairs (x1, y1),
 * (x2, y2), ... (xk, yk) such that the following conditions are met.
 *
 * 1 ≤ xi < yi ≤ n for all i between 1 and k, inclusive.
 * yi < xi+1 for all i between 1 and k-1, inclusive.
 * (xi+1 + yi+1) - (xi + yi) = c for all i between 1 and k-1, inclusive.
 *
 * If a list of pairs satisfies all of the above conditions, the list is said
 * to be stable. For any fixed n, c, and k, a stable list of k pairs is said
 * to be maximal if its sum of elements (the sum of all 2k integers it
 * contains) is the largest among all stable lists of k pairs.
 *
 * For instance, consider n=5, c=4, and k=2. There are two stable lists of
 * pairs: one is [(1, 2), (3, 4)] and the other is [(2, 3), (4, 5)]. The
 * latter is the only maximal stable list of pairs in this example as its
 * sum is (2+3+4+5) = 14.
 *
 * Given n, c, and k, find one maximal stable list of pairs, and return a
 * int[] that describes the list. Specifically, if (x1, y1), (x2, y2), ...,
 * (xk, yk) is your maximal stable list of pairs, you must return
 * { x1, y1, x2, y2, ..., xk, yk }.
 *
 * If there are many maximal stable lists of pairs, you may return any one
 * of them. If no stable list of pairs with the desired properties exists,
 * you must return an empty int[].
 *
 * Constraints
 * -	n will be between 1 and 100, inclusive.
 * -	c will be between 1 and 100, inclusive.
 * -	k will be between 1 and 100, inclusive.
 */

#include <iostream>
#include <vector>

using namespace std;

static int get_max_pairs1(int n, int c, int k, int n1, vector<int> &v)
{
    if (k == 0)
        return 1;

    while (n1 >= 1) {
        if (get_max_pairs1(n1-1, c, k-1, n-c+1, v)) {
            v.push_back(n1);
            v.push_back(n);
            return 1;
        }
        n1--;
    }

    return 0;
}

static void get_max_pairs(int n, int c, int k)
{
    vector<int> v;
    v.reserve(200);

    if (get_max_pairs1(n, c, k, n-1, v)) {
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << ' ';
        cout << endl;
    }
}

int main(void)
{
    get_max_pairs(12, 7, 3);

    return 0;
}
