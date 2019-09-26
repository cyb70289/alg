/* How much water can a pool with adjacent walls of various heights contain */

#include <iostream>

/* divide and conquer, O(nlogn) */
static int max_water(int height[], int left_idx, int right_idx)
{
    if ((right_idx - left_idx) <= 1) {
        return 0;
    }

    int max_idx = left_idx+1;

    for (int i = left_idx+2; i < right_idx; ++i) {
        if (height[i] > height[max_idx]) {
            max_idx = i;
        }
    }

    if (height[max_idx] <= height[left_idx] &&
        height[max_idx] <= height[right_idx]) {
        /* left, right surrounds the area  */
        int vol = 0;
        int max_height = std::min(height[left_idx], height[right_idx]);

        for (int i = left_idx+1; i < right_idx; ++i) {
            vol += (max_height - height[i]);
        }

        return vol;
    } else {
        return max_water(height, left_idx, max_idx) +
               max_water(height, max_idx, right_idx);
    }
}

/* O(n) */
static int max_water2(int height[], int left_idx, int right_idx)
{
    if ((right_idx - left_idx) <= 1) {
        return 0;
    }

    int vol = 0;
    int left_height_max = height[left_idx];
    int right_height_max = height[right_idx];

    while (left_idx < right_idx) {
        if (left_height_max <= right_height_max) {
            ++left_idx;
            if (height[left_idx] < left_height_max) {
                vol += (left_height_max - height[left_idx]);
            } else {
                left_height_max = height[left_idx];
            }
        } else {
            --right_idx;
            if (height[right_idx] < right_height_max) {
                vol += (right_height_max - height[right_idx]);
            } else {
                right_height_max = height[right_idx];
            }
        }
    }

    return vol;
}

int main(void)
{
    int height[] { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };

    int left_idx = 0;
    int right_idx = sizeof(height)/sizeof(height[0]) - 1;

    std::cout << max_water(height, left_idx, right_idx) << std::endl;
    std::cout << max_water2(height, left_idx, right_idx) << std::endl;

    return 0;
}
