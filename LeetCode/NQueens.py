class Solution:
    # @return an integer
    def totalNQueens(self, n):
        def _countQueens(max,n,prev):
            if n == 0:
                return 1
            res = 0
            if len(prev) == 0:
                cur = list(range(max))
            else:
                tmp = prev[:]
                for i in range(len(prev)):
                    dis = max - n - i
                    tmp.append(prev[i] - dis)
                    tmp.append(prev[i] + dis)
                cur = list(set(range(max)) - set(tmp))
            for i in cur:
                res += _countQueens(max,n-1,prev+[i])
            return res
        return _countQueens(n,n,[])