from os import sys
def solution():
	TEST_CASES = int(raw_input())

	for case in xrange(TEST_CASES):
		number_of_people = int(raw_input())
		people = []
		for person in xrange(number_of_people):
			arrival, departure = map(int, raw_input().split()) 
			people.append((arrival, 'c'))
			people.append((departure, 'b'))
		people.sort()
		max_people = 0
		current = 0
		for person in people:
			if person[1] == 'c':
				current += 1
			else:
				max_people = max(current, max_people)
				current -= 1
		print max_people
for input_size in ['C', 'M', 'G']:
	for index in xrange(0,10):
		out = sys.stdout
		_in = sys.stdin
		sys.stdin = open(input_size + str(index) + '.in', 'r')
		sys.stdout = open(input_size + str(index) + '.outI', 'w')
		solution()
		sys.stdout = out
		sys.stdin = _in
		


