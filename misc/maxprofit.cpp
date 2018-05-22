#include <iostream>
#include <climits>

using namespace std;

int get_min(const int *prices, int si, int ei)
{
    int m = INT_MAX;
    for (int i = si; i <= ei; i++)
        if (prices[i] < m)
            m = prices[i];
    return m;
}

int get_max(const int *prices, int si, int ei)
{
    int m = INT_MIN;
    for (int i = si; i <= ei; i++)
        if (prices[i] > m)
            m = prices[i];
    return m;
}

int maxprofit(const int *prices, int si, int ei)
{
    if (si == ei)
        return INT_MIN;

    int mi = (si + ei) / 2;

    int p1 = max(maxprofit(prices, si, mi), maxprofit(prices, mi+1, ei));
    int p2 = get_max(prices, mi+1, ei) - get_min(prices, si, mi);

    return max(p1, p2);
}

int main(void)
{
    int prices[] = { 7, 6, 8, 4, 9, 10, 1, 8, 9 };
    int len = sizeof(prices) / sizeof(prices[0]);

    cout << maxprofit(prices, 0, len-1) << endl;

    return 0;
}
