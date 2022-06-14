/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        auto dummy =  new ListNode(-1), cur = dummy;// 凡是需要操作一个链表的第一个结点的话, 最好有一个虚拟节点, dummy, 然后cur是该"和链表"的尾"指针"
        int t = 0;// t是进位temp变量
        while(l1 || l2 || t)
        {
            if(l1) t += l1->val, l1 = l1->next;
            if(l2) t += l2->val, l2 = l2->next;
            cur = cur->next = new ListNode(t % 10);// 长等式会先执行右边也就是先造节点, 然后再cur往后移一位
            t /= 10;
        }
        
        
        return dummy->next;// 题目要求返回真正的有效头结点"指针"
    }
};