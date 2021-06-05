class Solution(object):
    def lengthOfLongestSubstring(self, s):
        # beginning index of the subarray
        begin = 0
        # max subarray without repeating characters
        max_len = 0
        # dictionary which records the last seen position of a character
        last_seen = {}
        
        for i, c in enumerate(s):
            # update the beginning only if the current character has been visited and is after the
            # beginning of the current subarray
            if c in last_seen and last_seen[c] >= begin:
                begin = last_seen[c] + 1
            # update max length if current sub array length is greater
            cur_len = i-begin + 1
            max_len = cur_len if cur_len>max_len else max_len
            # always update the dictionary
            last_seen[c] = i
        return max_len
        