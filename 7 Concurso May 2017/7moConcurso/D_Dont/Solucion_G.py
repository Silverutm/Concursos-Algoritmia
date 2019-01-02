T = int(raw_input())
for c in xrange(T):
	n =  int(raw_input())
	activities = []
	for x in xrange(n):
		inicio, final = map(int, raw_input().strip().split(' '))
		activities.append([final, inicio])
	activities.sort()
	index = 0
	ans = 1
	for x in xrange(1, n):
		if activities[x][1] >= activities[index][0]:
			ans += 1
			index = x
	print ans