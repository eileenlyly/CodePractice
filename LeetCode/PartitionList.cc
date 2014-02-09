class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if(!head) return NULL;
        ListNode *large_head = new ListNode(-1);
        ListNode *small_head = new ListNode(-1);
        ListNode *large_cur = large_head;
        ListNode *small_cur = small_head;
        while(head){
            if(head -> val < x){
             small_cur -> next = head;
             small_cur = head;
            }
            if(head -> val >= x){
                large_cur -> next = head;
                large_cur = head;
            }
            head = head -> next;
        }
        large_cur -> next = NULL;
        if(small_head -> next) {
            small_cur -> next = large_head -> next;
            return small_head -> next;
        }
        return large_head -> next;
    }
};