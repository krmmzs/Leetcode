/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if(!head || !head->next) return nullptr;
        auto s = head, f = head->next;
        while(f)
        {
            s = s->next, f = f->next;
            if (!f) return nullptr;
            f = f->next;
            if (s == f)
            {
                s = head, f = f->next;
                while (s != f) s = s->next, f = f->next;
                return s;
            }
        }
        return nullptr;
    }
};
