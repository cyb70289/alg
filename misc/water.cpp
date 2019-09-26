/* How much water can a pool with adjacent walls of various heights contain */

#include <iostream>

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

int main(void)
{
    int height[] { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };

    int left_idx = 0;
    int right_idx = sizeof(height)/sizeof(height[0]) - 1;

    std::cout << max_water(height, left_idx, right_idx) << std::endl;

    return 0;
}
