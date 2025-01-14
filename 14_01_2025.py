class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        n = len(A)
        res = []
        def f(s1, s2):
            c = set()
            if len(s1)>len(s2):
                tmp = s1
                s1 = s2
                s2 = tmp
            # len(s1)<=len(s2)
            cnt = 0
            for x in s1:
                if x in s2:
                    cnt+=1
            return cnt


        a = set()
        b = set()
        for i in range(n):
            a.add(A[i])
            b.add(B[i])
            res.append(f(a,b))

        return res

        
