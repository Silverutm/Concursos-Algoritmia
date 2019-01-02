T = int(raw_input())
for c in xrange(T):
	n, m, k = map(int, raw_input().strip().split(' '))
	ans = n ^ m
	power = 0
	counter = 0
	while 1 << power <= ans:
		if 1 << power & ans:
			counter += 1
		power += 1

	if counter <= k:
		print "Son compatibles, sean felices por siempre :)"
	else :
		print "Langostas por siempre :("
