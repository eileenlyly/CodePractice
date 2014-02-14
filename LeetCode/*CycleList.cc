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
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        bool flag = true;
        while(fast != slow || flag){
            fast = fast -> next;
            if(!fast) return NULL;
            fast = fast -> next;
            if(!fast) return NULL;
            slow = slow -> next;
            flag = false;
        }
        ListNode *slow2 = head;
        while(slow != slow2){
            slow = slow -> next;
            slow2 = slow2 -> next;
        }
        return slow;
    }
};