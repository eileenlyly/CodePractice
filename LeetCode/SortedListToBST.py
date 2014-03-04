# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param head, a list node
    # @return a tree node
    def sortedListToBST(self, head):
        def _sortedListToBST(head):
            if head is None:
                return None
            mid = findMid(head)
            root = TreeNode(mid.val)
            root.right = _sortedListToBST(mid.next)
            mid.next = None
            if head != mid:
                root.left = _sortedListToBST(head)
            return root
        def findMid(head):
            if head.next is None:
                return head
            fast = head.next.next
            slow = head
            flag = False
            while fast != None:
                fast = fast.next
                if flag:
                    slow = slow.next
                flag = not flag
            mid = slow.next
            slow.next = None
            return mid
        return _sortedListToBST(head)
            
            