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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *pre = head;
        ListNode *current = head;
        bool fnish_l1 = 0;
        bool fnish_l2 = 0;
        int extra_adder = 0;
        while (1)
        {
            int sum = 0;
            if (!fnish_l1 && !fnish_l2){
                sum = l1->val + l2->val + extra_adder;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(fnish_l1 && !fnish_l2){
                if (extra_adder == 0)
                {
                    pre->next = l2;
                    break;
                }
                sum = l2->val + extra_adder;
                l2 = l2->next;
            }
            else if(!fnish_l1 && fnish_l2){
                if (extra_adder == 0)
                {
                    pre->next = l1;
                    break;
                }
                sum = l1->val + extra_adder;
                l1 = l1->next;
            }
            else{
                if (extra_adder == 0){
                    break;
                }
                else{
                    current = new ListNode(0);
                    current->val = extra_adder;
                    current->next = nullptr;
                    pre->next = current;
                    break;
                }
            }
            if (sum > 9)
            {
                extra_adder = 1;
                current->val = sum % 10;
                pre->next = current;
            }
            else
            {
                extra_adder = 0;
                current->val = sum;
                pre->next = current;
            }
            pre = current;
            current = new ListNode(0);
            pre->next = nullptr;
            if (l1 == nullptr){
                fnish_l1 = 1;
            }
            if (l2 == nullptr){
                fnish_l2 = 1;
            }
        }
        return head;
    }
};
