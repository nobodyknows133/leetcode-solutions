class Solution:
    def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:
        res = []

        f = defaultdict(int)
        for word in words2:
            fword = Counter(word)
            for k,v in fword.items():
                f[k]=max(f[k],v)
            
        def isUni(word):
            fword = Counter(word)
            for k,v in f.items():
                if k not in fword or fword[k]<f[k]:
                    return False
            return True
            
        for a in words1:
            if isUni(a):
                res.append(a)
        
        return res
        
