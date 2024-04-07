#Length of Longest Substring without repeating characters
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        maxLen = 0
        currLen = 0
        charSoFar = set()
        i = 0
        j = 0

        if len(s) == 1:
            return 1

        while i < len(s):
            if s[i] not in charSoFar:
                charSoFar.add(s[i])
                currLen+=1
                maxLen=max(currLen,maxLen)
                i+=1
            else:
                charSoFar.remove(s[j])
                j+=1
                currLen-=1
        return maxLen