from math import ceil
from os import sys

def solution():
	TEST_CASES = int(raw_input())

	for case in xrange(TEST_CASES):
		_n, _k = map(float, raw_input().split())
		print int(ceil(_n / _k))

for input_size in ['C', 'G']:
	for index in xrange(0,10):
		out = sys.stdout
		_in = sys.stdin
		sys.stdin = open(input_size + str(index) + '.inR', 'r')
		sys.stdout = open(input_size + str(index) + '.outI', 'w')
		solution()
		sys.stdout = out
		sys.stdin = _in
		