from os import sys
def solution():
	TEST_CASES = int(raw_input())

	for case in xrange(TEST_CASES):
		year = int(raw_input())
		if year % 165 == 0:
			print "Descongelar a mi rey."
		else:
			print "Dejar descansar a mi rey."

for input_size in ['C', 'M', 'G']:
	for index in xrange(0,10):
		out = sys.stdout
		_in = sys.stdin
		sys.stdin = open(input_size + str(index) + '.inR', 'r')
		sys.stdout = open(input_size + str(index) + '.outI', 'w')
		solution()
		sys.stdout = out
		sys.stdin = _in
		