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
    void reorderList(ListNode* head) {
        vector<int>temp;

        ListNode *curr = head;


        while(curr){
            temp.push_back(curr->val);
            curr = curr->next;
        }

        int left = 0;
        int n = temp.size();
        int right = n - 1;

        vector<int> sol;
        while(left < right){
            sol.push_back(temp[left]);
            sol.push_back(temp[right]);
            left++;
            right--;
        }
        if(left == right){
            sol.push_back(temp[left]);
        }

        curr = head;

        for(int i = 0; i < sol.size(); i++){
            curr->val = sol[i];
            curr = curr->next;
        }


    
    }
};
