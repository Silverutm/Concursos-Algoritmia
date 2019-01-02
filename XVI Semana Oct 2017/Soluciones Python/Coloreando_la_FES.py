from math import ceil
TEST_CASES = int(raw_input())

for case in xrange(TEST_CASES):
	_n, _k = map(float, raw_input().split())
	print int(ceil(_n / _k))