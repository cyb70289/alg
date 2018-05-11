/* https://community.topcoder.com/stat?c=problem_statement&pm=14848
 * You are given a set of colored points on a straight line.
 * You play a game with these points. The game is a sequence of moves. In each
 * move you have to erase two points that are adjacent and share the same color.
 * (Two points are adjacent if there is no other point between them.
 * Distances don't matter.)
 * You are given the String points. Each character of points describes the color
 * of one point, in the order in which they are arranged on the line at the
 * beginning of the game. (Different letters represent different colors.)
 * Compute and return the maximum number of moves you can make.
 *
 * Constraints
 * -	points will contain between 1 and 50 characters, inclusive.
 * -	Each character in points will be a lowercase English letter ('a'-'z').
*/

#include <iostream>
#include <string>

using namespace std;

int max_moves(string &s)
{
    for (int i = 0; i < (int)s.length()-1; i++) {
        if (s[i] == s[i+1]) {
            s.erase(i, 2);
            return max_moves(s) + 1;
        }
    }
    return 0;
}

int main(void)
{
    string s = "wasitacarooracatisaw";
    cout << max_moves(s) << endl;

    return 0;
}
