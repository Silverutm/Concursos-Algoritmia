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