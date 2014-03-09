class Solution:
    # @param strs, a list of strings
    # @return a list of strings
    def anagrams(self, strs):
        map = {}
        res = []
        for i in range(len(strs)):
            s = "".join(sorted(strs[i]))
            if s not in map:
                map[s] = [i]
            else:
                map[s].append(i)
        for k in map:
            ind = map[k]
            if len(ind) > 1:
                for i in range(len(ind)):
                    res.append(strs[ind[i]])
        return res
        