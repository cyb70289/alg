/* https://www.geeksforgeeks.org/length-smallest-sub-string-consisting-maximum-distinct-characters */

#include <iostream>
#include <string>

using namespace std;

static int smallest(const string &s)
{
    const int len = s.length();
    int dist[len][len];    /* [start index][substr len - 1] */
    int maxdist = 1;
    int sublen = 1;

    for (int i = 0; i < len; i++)
        dist[i][0] = 1;

    for (int l = 1; l < len; l++) {
        for (int i = 0; i < len-l; i++) {
            int t = ((s[i] != s[i+l]) &&
                     (l == 1 || dist[i+1][l-1] != dist[i+1][l-2]));
            dist[i][l] = dist[i][l-1] + t;
            if (dist[i][l] > maxdist) {
                maxdist = dist[i][l];
                sublen = l+1;
            }
        }
    }

    return sublen;
}

int main(void)
{
    cout << smallest("GEEKSGEEKSFOR") << endl;
    return 0;
}
