TEST_CASES = int(raw_input())

for case in xrange(TEST_CASES):
	year = int(raw_input())
	if year % 165 == 0:
		print "Descongelar a mi rey."
	else:
		print "Dejar descansar a mi rey."