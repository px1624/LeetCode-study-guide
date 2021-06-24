class Solution:
    def __init__(self):
        self.ops = set(['+', '-', '*'])
        self.memo = {}
        
    def diffWaysToCompute(self, expression: str) -> List[int]:
        return self.find_result(expression)
    
    def find_result(self, expression):
        contains_ops = False
        results = []
        # return if we have seen this expression before
        if expression in self.memo:
            return self.memo[expression]
        # split expression by operator characters and group left and right
        # substrings by parenthesis. Recursively do it until string contains
        # no operator characters.
        for i, c in enumerate(expression):
            # look for operator characters
            if c in self.ops:
                contains_ops = True
                # get left substring and right substring
                left = self.find_result(expression[:i])
                right = self.find_result(expression[i+1:])
                # compute all combinations of left and right results
                for l_num in left:
                    for r_num in right:
                        results.append(self.compute(l_num, r_num, c))
        # if expression is a number, return the number       
        if not contains_ops:
            results.append(int(expression))
        # record the result for memoization
        self.memo[expression] = results
        return results
    
    # compute the result of a simplest expression
    # which consists of 2 numbers and a operator
    def compute(self, l, r, op):
        if op == '+':
            return l+r
        elif op == '-':
            return l-r
        else:
            return l*r
