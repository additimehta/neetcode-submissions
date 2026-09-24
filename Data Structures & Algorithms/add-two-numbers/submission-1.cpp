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

        int carry = 0;
        ListNode *sol = nullptr;
        ListNode *tail = nullptr;
        while(l1 || l2){

            int sum = 0;
            if(l1 == nullptr){
                sum = l2->val + carry;
            }else if(l2 == nullptr){
                sum  = l1->val + carry;
            }else{
                sum = l1->val + l2->val + carry;
            }

            carry = sum/10;
            int digit = sum %10;

            ListNode *node = new ListNode(digit);

            if(sol == nullptr){
                sol = node;
                tail = node;
            }else{
                tail->next = node;
                tail = tail->next;

            }

            if(l1){
                l1 = l1->next;
            }

            if(l2){
                l2 = l2->next;
            }


        }

        if(carry > 0){
            ListNode *carryNode = new ListNode(carry);
            tail->next = carryNode;
            tail = tail->next;
        }
 

        return sol;
        
    }
};
