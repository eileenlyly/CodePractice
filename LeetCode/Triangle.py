class Solution:
    # @param triangle, a list of lists of integers
    # @return an integer
    def minimumTotal(self, triangle):
        if len(triangle) == 0:
            return 0
        def _minTotal(triangle, pre):
            if len(triangle) == 0:
                return pre
            cur = triangle[0]
            cur[0] += pre[0]
            cur[len(cur)-1] += pre[len(pre)-1]
            for i in range(1,len(cur)-1):
                cur[i] += min(pre[i-1],pre[i])
            return _minTotal(triangle[1:],cur)
        last_row = _minTotal(triangle[1:],triangle[0])
        return min(last_row)
            