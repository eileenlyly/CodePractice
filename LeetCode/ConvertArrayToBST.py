# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param num, a list of integers
    # @return a tree node
    def sortedArrayToBST(self, num):
        def _sortedArrayToBST(num):
            if len(num) == 0:
                return None
            mid = num[len(num)/2]
            root = TreeNode(mid)
            if len(num) > 1:
                root.left = _sortedArrayToBST(num[0:len(num)/2])
            if len(num) > 2:
                root.right = _sortedArrayToBST(num[len(num)/2+1:len(num)])
            return root
        return _sortedArrayToBST(num)
        