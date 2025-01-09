class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        res = 0
        n = len(pref)
        for i in range(len(words)):
            res = res + (1 if (len(words[i])>=n and words[i][:n]==pref) else 0)

        return res
        
