from math import factorial
T = int(raw_input())
for c in xrange(T):
	m, n, k = map(int, raw_input().strip().split(' '))
	ans = (factorial(n + m) / (factorial(n) * factorial(m))) * (n + m) * k
	print ans
