# Time:  O(n)
# Space: O(c), c is unique count of pattern and words

# Given a pattern and a string str, find if str follows the same pattern.
#
# Examples:
#   1. pattern = "abba", str = "dog cat cat dog" should return true.
#   2. pattern = "abba", str = "dog cat cat fish" should return false.
#   3. pattern = "aaaa", str = "dog cat cat dog" should return false.
#   4. pattern = "abba", str = "dog dog dog dog" should return false.
#
# Notes:
#   1. Both pattern and str contains only lowercase alphabetical letters.
#   2. Both pattern and str do not have leading or trailing spaces.
#   3. Each word in str is separated by a single space.
#   4. Each letter in pattern must map to a word with length that is at least 1.

# Lengthy code but saving more spaces
class Solution(object):
    # Word generates at a time without saving all the words.
    class WordGenerator(object):
        def __init__(self, str):
            self.str = str
        
        def __iter__(self):
            w = ""
            for c in self.str:
                if c == ' ':
                    yield w
                    w = ""
                else:
                    w += c
            yield w

    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        if len(pattern) != self.wordCount(str):
            return False

        w2p, p2w = {}, {}
        for i, w in enumerate(self.WordGenerator(str)):
            p = pattern[i]
            if w not in w2p and p not in p2w:
                # Build mapping.
                w2p[w] = p
                p2w[p] = w 
            elif w not in w2p or w2p[w] != p:
                # Contradict mapping.
                return False
        return True
    
    def wordCount(self, str):
        cnt = 1 if str else 0
        for c in str:
            if c == ' ':
                cnt += 1
        return cnt
