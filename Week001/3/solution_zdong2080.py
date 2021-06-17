class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s) == 1: return 1
        finalSize = 0
        size = 0
        dic = {}
        i = 0
        while i < len(s):
            if s[i] not in dic:
                dic[s[i]] = i
                size += 1
                i += 1
            else:
                i = dic[s[i]]+1
                dic = {}
                if size > finalSize:
                    finalSize = size
                    size = 0
                else:
                    size = 0
        if size > finalSize: return size
        else: return finalSize