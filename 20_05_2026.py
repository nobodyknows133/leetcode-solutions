class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        n = len(A)
        sa = set()
        sb = set()
        res = []
        for i in range(n):
            sa.add(A[i])
            sb.add(B[i])
            res.append(len(sa & sb))
        return res
