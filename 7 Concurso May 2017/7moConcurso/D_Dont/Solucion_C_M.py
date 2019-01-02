T = int(raw_input())
for c in xrange(T):
	n =  int(raw_input())
	activities = []
	for x in xrange(n):
		inicio, final = map(int, raw_input().strip().split(' '))
		activities.append([inicio, final])
	for i in xrange(1, n):
		for j in xrange(0, n - i):
			if activities[j][1] > activities[j+1][1]:
				temp1 = activities[j][1]
				temp2 = activities[j][0]
				activities[j][1] = activities[j+1][1]
				activities[j][0] = activities[j+1][0]
				activities[j+1][1] = temp1
				activities[j+1][0] = temp2
	index = 0
	ans = 1
	for x in xrange(1, n):
		if activities[x][0] >= activities[index][1]:
			ans += 1
			index = x
	print ans