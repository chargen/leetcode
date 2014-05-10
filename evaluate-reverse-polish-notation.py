import math

class Solution:
    # @param tokens, a list of string
    # @return an integer
    def evalRPN(self, tokens):
    	stack = []
        for s in tokens:
        	if "+-*/".count(s) > 0:
        		b = stack.pop()
        		a = stack.pop()
        		c = 0
	        	if s == "+":
        			c = a+b
        		elif s == "-":
        			c = a-b
        		elif s == "*":
	        		c = a*b
        		elif s == "/":
        			c = int(float(a)/b)
        		#print a,s,b,"=",c
        		stack.append(c)
        	else:
        		stack.append(int(s))
        return stack.pop()

sol = Solution()
print sol.evalRPN(["3","-4","+"])
print sol.evalRPN(["2", "1", "+", "3", "*"])
print sol.evalRPN(["4", "13", "5", "/", "+"])
print sol.evalRPN(["10","6","9","3","+","-11","*","/","*","17","+","5","+"])