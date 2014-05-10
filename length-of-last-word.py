class Solution:
    # @param s, a string
    # @return an integer
    def lengthOfLastWord(self, s):
        L = s.rstrip().split(" ")
        return len(L) == 0 and 0 or len(L[-1]) 