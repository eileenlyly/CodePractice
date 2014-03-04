class Solution:
    # @param S, a list of integer
    # @return a list of lists of integer
    def subsets(self,S):
        def _subset(S):
            if len(S) == 0:
                return [[]]
            sub = _subset(S[1:])
            ori = len(sub)
            for i in range(ori):
                sub.append(sub[i] + S[0:1])
            return sub
        S.sort(reverse = True)
        return _subset(S)
        