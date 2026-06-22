from collections import Counter
class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        f = Counter(text)
        return min(f.get("a",0),f.get("b",0),f.get("l",0)//2,f.get("o",0)//2,f.get("n",0))

        
