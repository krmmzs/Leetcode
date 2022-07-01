/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (!head || !head->next) return false;
        auto f = head->next, s = head;
        while (f)
        {
            s = s->next, f = f->next;
            if (!f) return false;
            f = f->next;
            if (s == f) return true;
        }
        return false;
    }
};
