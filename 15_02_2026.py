class Solution:
    def addBinary(self, a: str, b: str) -> str:
        res = ""
        a = a[::-1]
        b = b[::-1]
        c = 0
        l = max(len(a),len(b))
        if len(a)<l:
            a = a + "".join(["0"]*(l-len(a)))
        if len(b)<l:
            b = b + "".join(["0"]*(l-len(b)))

        for i in range(l):
            val = int(a[i])+int(b[i])+c
            if val == 0 or val == 1:
                res = res + str(val)
                c = 0
            elif val == 2:
                res = res + "0"
                c = 1
            else:
                res = res + "1"
                c = 1
        if c == 1:
            res = res + "1"
        return res[::-1]
