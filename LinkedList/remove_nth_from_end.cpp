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
        ListNode *slow,*fast,*prev;
        prev=NULL;
        fast=head,slow=head;
        int k=1;
        while(k<n){
            fast=fast->next;
            k++;
        }
        if(fast->next==NULL){
            slow=slow->next;
            return slow;
        }
        while(fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next;
        }
        prev->next=slow->next;
        return head;
    }
};