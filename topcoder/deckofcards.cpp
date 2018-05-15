/* https://community.topcoder.com/stat?c=problem_statement&pm=14846&rd=17103
 *
 * You found a deck of slightly non-traditional playing cards. Each card has a
 * value and a suit. The value of each card is a positive integer, and the suit
 * is a lowercase English letter ('a'-'z'). We will use (v, s) to denote a card
 * with value v and suit s.
 *
 * You want to know whether the deck is perfect. A perfect deck has two
 * properties:
 * -   All cards in the deck are distinct. (I.e., no two cards share both value
 *     and suit.)
 * -   For any two cards (v1, s1) and (v2, s2) in the deck, the deck also
 *     contains the cards (v1, s2) and (v2, s1).
 *
 * You are given the following data:
 * -   a int n: the number of cards in the deck
 * -   a int[] value with n elements: the values of the cards in the deck
 *     a String suit with n elements: the suits of the cards in the deck
 *
 * More precisely, for each valid i, (value[i], suit[i]) is one of the cards
 * in the deck. Return "Perfect" if the deck is perfect and "Not perfect"
 * otherwise. Note that the quotes are only for clarity and that the return
 * value is case-sensitive.
 *
 * Constraints
 * -	n will be between 1 and 50, inclusive.
 * -	value will contain exactly n elements.
 * -	Each element of value will be between 1 and 1,000,000,000, inclusive.
 * -	suit will be of length n exactly.
 * -	Suit will only contain lower-case alphabets ('a'-'z').
 */

#include <iostream>
#include <algorithm>

using namespace std;

int sortbysec(const pair<int,char> &a, const pair<int,char>&b)
{
    return a.second < b.second;
}

int is_perfect(int n, const int *value, const char *suit)
{
    vector<pair<int, char>> vp;
    for (int i = 0; i < n; i++)
        vp.push_back(make_pair(value[i], suit[i]));

    stable_sort(vp.begin(), vp.end(), sortbysec);

    int uniq_suits = 0, prev_suit = -1;
    for (int i = 0; i < n; i++) {
        if (vp[i].second != prev_suit) {
            prev_suit = vp[i].second;
            uniq_suits++;
        }
    }

    stable_sort(vp.begin(), vp.end());

    int uniq_values = 0, prev_value = -1;
    for (int i = 0; i < n; i++) {
        if (vp[i].first != prev_value) {
            prev_value = vp[i].first;
            uniq_values++;
        }
    }

    if (n != uniq_values*uniq_suits)
        return 0;

    for (int i = 1; i < n; i++)
        if (vp[i].first == vp[i-1].first && vp[i].second == vp[i-1].second)
            return 0;

    return 1;
}

int main(void)
{
    const int value[] =  {2, 3, 2, 3};
    const char *suit = "hcch";
    const int n = sizeof(value) / sizeof(value[0]);

    int perfect = is_perfect(n, value, suit);
    cout << (perfect ? "Perfect" : "Not Perfect") << endl;

    return 0;
}
