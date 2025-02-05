class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        n = len(s1)
        c1 = list(s1)
        c2 = list(s2)
        if c1 == c2:
            return True

        for i in range(n):
            # swap i in c1 and c2
            if i < n:
                c1[i], c2[i] = c2[i], c1[i]
                if c1 == c2:
                    return True
                c1[i], c2[i] = c2[i], c1[i]
        

        for i in range(n):
            for j in range(n):
                if i==j:
                    continue
                if c1[i]!=c1[j]:
                    c1[i],c1[j] = c1[j], c1[i]
                    if c1==c2:
                        return True
                    c1[i],c1[j] = c1[j], c1[i]

        for i in range(n):
            for j in range(n):
                if i==j:
                    continue
                if c2[i]!=c2[j]:
                    c2[i],c2[j] = c2[j], c2[i]
                    if c1==c2:
                        return True
                    c2[i],c2[j] = c2[j], c2[i]

        
        return False
            


        
