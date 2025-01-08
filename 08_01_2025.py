class Solution:
    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        res = 0
        n = len(words)

        def isPrefixAndSuffix(str1, str2):
            n1 = len(str1)
            n2 = len(str2)
            if n1>n2:
                return False
            # n1<=n2
            pref = str2[:n1]
            suff = str2[n2-n1:]
            if pref==suff==str1:
                return True
            else:
                return False


        for i in range(n):
            for j in range(i+1,n):
                if isPrefixAndSuffix(words[i],words[j]):
                    res+=1
        
        return res
