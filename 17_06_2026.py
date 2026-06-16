class Solution:
    def processStr(self, s: str) -> str:
        res = []
        for x in s:
            if x=="*":
                if len(res)!=0:
                    res.pop()
            elif x=="#":
                res = res + res.copy()
            elif x=="%":
                res = list(reversed(res))
            else:
                res.append(x)

        return "".join(res)
        
