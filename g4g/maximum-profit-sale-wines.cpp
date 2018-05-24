/* https://www.geeksforgeeks.org/maximum-profit-sale-wines */

#include <iostream>

using namespace std;

int maxprofit(int *prices, int len)
{
    int profits[len][len];
    int maxp = -1;

    for (int i = 0; i < len; i++) {
        profits[len-1][i] = len*prices[i];
        maxp = max(maxp, profits[len-1][i]);
    }

    for (int i = len-2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            int p1 = profits[i+1][j] + prices[j+len-1-i]*(i+1);
            int p2 = profits[i+1][j+1] + prices[j]*(i+1);
            profits[i][j] = max(p1, p2);
            maxp = max(maxp, profits[i][j]);
        }
    }

    return maxp;
}

int main(void)
{
    int prices[] = { 2, 4, 6, 2, 5 };
    cout << maxprofit(prices, sizeof(prices)/sizeof(prices[0])) << endl;

    return 0;
}
