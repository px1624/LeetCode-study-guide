class Solution(object):
    def minPartitions(self, n):
        """
        :type n: str
        :rtype: int
        """

        maxd = 1
        for item in n:
            if int(item) > maxd:
                maxd = int(item)
        return maxd