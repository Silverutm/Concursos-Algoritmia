from math import sqrt
from os import sys

def solution():
	TEST_CASES = int(raw_input())

	for case in xrange(TEST_CASES):
		_xi = float(raw_input())
		print int(round(((1+sqrt(3))**(_xi+2)-(1-sqrt(3))**(_xi+2))/(4*sqrt(3)))) % 1000000007 

for input_size in ['C', 'M', 'G']:
	for index in xrange(0,10):
		out = sys.stdout
		_in = sys.stdin
		sys.stdin = open(input_size + str(index) + '.inR', 'r')
		sys.stdout = open(input_size + str(index) + '.outI', 'w')
		solution()
		sys.stdout = out
		sys.stdin = _in
		