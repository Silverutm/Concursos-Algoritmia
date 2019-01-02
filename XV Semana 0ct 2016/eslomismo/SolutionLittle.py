n = int(input())

for caso in range(n):
	p, r, m, n = [int(x) for x in input().split()]

	if ((m+1)**n)%(p**r) == 0:
		print("Lo lograste")
	else :
		print("Sad eyes")



	# p, r, m, n = [int(x) for x in input().split()]
	# if (m+1) % p == 0 :
	# 	pot = p
	# 	k = 1
	# 	while pot < m+1 :
	# 		pot *= p
	# 		k += 1
	# 	k *= n
	# 	print("k: ", k)
	# 	if k%r == 0:
	# 		print("Lo lograste")
	# 		continue
	# print("Sad eyes")
