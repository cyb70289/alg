/* http://blog.gainlo.co/index.php/2016/04/08/if-a-string-contains-an-anagram-of-another-string */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int contains_anagram(const string &s1, const string &s2)
{
    vector<int> a1(256), a2(256);

    if (a1.size() < a2.size())
        return 0;

    /* hash s2 */
    for (auto c: s2)
        a2[c]++;

    /* hash s1 window */
    for (int i = 0; i < s2.size(); i++)
        a1[s1[i]]++;
    if (a1 == a2)
        return 1;
    for (int i = s2.size(); i < s1.size(); i++) {
        a1[s1[i]]++;
        a1[s1[i-s2.size()]]--;
        if (a1 == a2)
            return 1;
    }

    return 0;
}

int main(void)
{
    const string s1 = "coding interview questions";
    const string s2 = "weivretni";

    cout << contains_anagram(s1, s2) << endl;

    return 0;
}
