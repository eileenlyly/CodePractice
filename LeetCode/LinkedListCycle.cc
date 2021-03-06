/**
 * Given a linked list, determine if it has a cycle in it.
Follow up:
Can you solve it without using extra space?
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode * fast;
        ListNode * slow;
        if(head == NULL) return false;
        fast = head;
        slow = head;
        while(fast -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast == NULL) return false;
            if(fast == slow) return true;
        }
        return false;
    }
};