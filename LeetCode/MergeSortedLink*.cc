
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode newhead(-1);
        ListNode *curr = &newhead;
        while(l1 != NULL && l2 != NULL){
            if(l1 -> val < l2 -> val){
                curr -> next = l1;
                l1 = l1 -> next;
            }
            else{
                curr -> next = l2;
                l2 = l2 -> next;
            }
            curr = curr -> next;
        }
        if(!l1) curr -> next = l2;
        else curr -> next = l1;
        return newhead.next;
    }
};
Submit Solution
