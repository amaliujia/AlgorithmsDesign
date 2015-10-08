class Solution(object):
    def diffWaysToCompute(self, input):
        res = []
        for i in xrange(len(input)):
            if not input[i].isdigit():
                res_left = self.diffWaysToCompute(input[0:i])
                res_right = self.diffWaysToCompute(input[i+1:])
                for l in res_left:
                    for r in res_right:
                        if input[i] == '*':
                            res.append(l * r)
                        elif input[i] == '-':
                            res.append(l - r)
                        else:
                            res.append(l + r)
        if input.isdigit():
            res.append(int(input))
        return res
