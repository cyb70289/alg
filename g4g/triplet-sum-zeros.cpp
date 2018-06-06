/* https://www.geeksforgeeks.org/find-triplets-array-whose-sum-equal-zero */

#include <iostream>
#include <unordered_map>

using namespace std;

void find_sum(unordered_map<int, int> amap, int *a, int len, int s)
{
    for (int i = 0; i < len-1; i++) {
        amap[a[i]]--;
        if (amap.find(s-a[i]) != amap.end() && amap[s-a[i]] > 0)
            cout << -s << ',' << a[i] << ',' << s-a[i] << endl;
    }
}

void triple_sum_zero(int *a, int len)
{
    unordered_map<int, int> amap;

    for (int i = 0; i < len; i++) {
        if (amap.find(a[i]) == amap.end())
            amap[a[i]] = 1;
        else
            amap[a[i]]++;
    }

    for (int i = 0; i < len-2; i++) {
        amap[a[i]]--;
        find_sum(amap, a+i+1, len-i-1, -a[i]);
    }
}

int main(void)
{
    int a[] = { 0, -1, 2, -3, 1 };

    triple_sum_zero(a, sizeof(a)/sizeof(a[0]));

    return 0;
}
