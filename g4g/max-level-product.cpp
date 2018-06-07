/* https://www.geeksforgeeks.org/find-maximum-level-product-binary-tree */

#include <iostream>
#include <queue>
#include <cstdint>

using namespace std;

struct node {
    int v;
    node *left, *right;
};

int max_level_product(const node *root)
{
    int prev_level = 0;
    int mul = INT32_MIN, max_mul = INT32_MIN;
    queue<pair<const node*,int>> q;

    q.push(make_pair(root, 1));
    while (!q.empty()) {
        pair<const node*,int> nl = q.front();
        q.pop();
        const node *node = nl.first;
        int level = nl.second;

        if (level != prev_level) {
            if (mul > max_mul)
                max_mul = mul;
            mul = 1;
            prev_level = level;
        }
        mul *= node->v;

        if (node->left)
            q.push(make_pair(node->left, level+1));
        if (node->right)
            q.push(make_pair(node->right, level+1));
    }

    if (mul > max_mul)
        max_mul = mul;

    return max_mul;
}

int main(void)
{
    node n6 = { 6, NULL, NULL },
         n7 = { 7, NULL, NULL },
         n8 = { 8, &n6, &n7 },
         n4 = { 4, NULL, NULL },
         n5 = { 5, NULL, NULL },
         n2 = { 2, &n4, &n5 },
         n3 = { 3, NULL, &n8 },
         n1 = { 1, &n2, &n3 };

    cout << max_level_product(&n1) << endl;

    return 0;
}
