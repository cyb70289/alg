/* https://community.topcoder.com/stat?c=problem_statement&pm=14908
 *
 * A new social network automatically matches people together based upon a
 * shared interest. A list of interests for each member of the social network
 * is given in the String[] interests. Each element represents the interests
 * of a single member: each character ('A'-'Z') represents a different interest.
 * Two individuals become friends if they have at least one interest in common.
 * Return the average number of friends each member has.
 *
 * Constraints
 * -	interests will contain between 2 and 50 elements, inclusive.
 * -	Each character in each element of interests will be an uppercase
 *  	English letter ('A'-'Z').
 * -	The characters in each element of interests will be distinct.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

double avg_friends(vector<string> &str)
{
    int count[26];

    for (int i = 0; i < 26; i++)
        count[i] = 0;

    for (int i = 0; i < str.size(); i++)
        for (int j = 0; j < str[i].size(); j++)
            count[str[i][j]-'A']++;

    double sum = 0;
    for (int i = 0; i < 26; i++)
        sum += count[i] * (count[i]-1);

    return sum / str.size();
}

int main(void)
{
    vector<string> str = {"ABC", "DE", "FGHIJA"};
    cout << avg_friends(str) << endl;

    return 0;
}
