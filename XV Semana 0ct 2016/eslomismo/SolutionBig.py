n = int(input())

for caso in range(n):
	p, r, m, n = [int(x) for x in input().split()]
	if (m+1) % p == 0 :
		pot = p
		k = 0

		while (m+1) % pot == 0  :
			pot *= p
			k += 1

		k *= n
		#print("k: ", k)
		if k >= r:
			print("Lo lograste")
			continue
	print("Sad eyes")
