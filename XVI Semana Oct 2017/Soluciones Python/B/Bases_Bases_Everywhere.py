from os import sys

BASE_CHARS = {'A' : 10, 'B' : 11, 'C' : 12, 'D' : 13, 10 : 'A', 11 : 'B', 12 : 'C', 13 : 'D', \
			'E' : 14, 'F' : 15, 14: 'E', 15 : 'F'}

BASE = None
def add_units(a, b, c):
	global BASE_CHARS, BASE
	#print a, b
	carriage = 0
	if a in BASE_CHARS:
		a = BASE_CHARS[a]
	if b in BASE_CHARS:
		b = BASE_CHARS[b]
	ans = int(a) + int(b) + int(c)
	if ans >= BASE:
		ans -= BASE
		carriage = 1
	#print "ans {}".format(ans)
	if ans in BASE_CHARS:
		return carriage, BASE_CHARS[ans]
	return carriage, ans

def sum_base14(a, b):
	_a = a[::-1]
	_b = b[::-1]
	rem_dig = ""
	carriage = 0
	result = ""
	num_rem_dig = len(a) - len(b)
	if num_rem_dig:
		rem_dig = a[:num_rem_dig]
	for i in xrange(len(b)):
		carriage, unit = add_units(_a[i], _b[i], carriage)
		#print "carriage {0} unit {1}".format(carriage, unit)
		result += str(unit)
	if carriage:
		if num_rem_dig:
			result += sum_base14(rem_dig, str(carriage))
			return result[::-1]
		return str(carriage) + result[::-1]
	return rem_dig + result[::-1]

def sum_of_digits(number):
	if len(number) == 1:
		return number
	ans = '0'
	for i in xrange(len(number)):
		ans = sum_base14(ans, number[i])
	return sum_of_digits(ans)
def solution():
	global TEST_CASES, BASE
	TEST_CASES = int(raw_input())

	for case in xrange(TEST_CASES):
		number, BASE = raw_input().split()
		BASE = int(BASE)
		print sum_of_digits(number)
for input_size in ['C', 'M', 'G']:
	for index in xrange(0,10):
		out = sys.stdout
		_in = sys.stdin
		sys.stdin = open(input_size + str(index) + '.in', 'r')
		sys.stdout = open(input_size + str(index) + '.outI', 'w')
		solution()
		sys.stdout = out
		sys.stdin = _in
		


