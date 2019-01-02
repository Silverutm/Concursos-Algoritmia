from math import sqrt
TEST_CASES = int(raw_input())

for case in xrange(TEST_CASES):
	_xi = float(raw_input())
	print int(round(((1+sqrt(3))**(_xi+2)-(1-sqrt(3))**(_xi+2))/(4*sqrt(3)))) % 1000000007 