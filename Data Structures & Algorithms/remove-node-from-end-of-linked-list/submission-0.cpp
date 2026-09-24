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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head){
            return nullptr;
        }

        vector<int> temp;
        ListNode *curr = head;
        while(curr){
            temp.push_back(curr->val);
            curr = curr->next;
        }

        int tn = temp.size();
        int remove = tn - n;

        temp.erase(temp.begin() + remove);

        ListNode *newHead = nullptr;
        ListNode *tail = nullptr;

        for(int i = 0; i < temp.size(); i++){
            ListNode *newNode  = new ListNode(temp[i]);
            if(newHead == nullptr){
                newHead = newNode;
                tail = newNode;
            }else{
                tail->next = newNode;
                tail = newNode;
            }

        }

        return newHead;

        
    }
};
