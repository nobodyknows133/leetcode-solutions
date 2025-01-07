class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        res = []
        for i, word in enumerate(words):
            for j,pos in enumerate(words):
                if i==j:
                    continue
                if pos in word:
                    res.append(pos)
        return list(set(res))
        
