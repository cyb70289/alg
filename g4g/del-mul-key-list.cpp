/* https://www.geeksforgeeks.org/delete-multiple-occurrences-of-key-in-linked-list-using-double-pointer */

#include <iostream>

using namespace std;

struct node {
    int v;
    node *next;
};

node *del_key(node *head, int v)
{
    if (head == NULL)
        return NULL;

    if (head->v == v)
        return del_key(head->next, v);

    node *prev = head, *p = head->next;
    while (p) {
        if (p->v == v) {
            prev->next = del_key(p, v);
            break;
        }
        prev = prev->next;
        p = p->next;
    }

    return head;
}

int main(void)
{
    node n1 = { 2, NULL },
         n2 = { 3, &n1 },
         n3 = { 4, &n2 },
         n4 = { 2, &n3 },
         n5 = { 2, &n4 };

    node *head = del_key(&n5, 2);
    while (head) {
        cout << head->v << endl;
        head = head->next;
    }

    return 0;
}
