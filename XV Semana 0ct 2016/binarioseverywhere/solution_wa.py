#! /usr/bin/env python3

N = int(input())
for caso in range(N):
	a, p = input().split()
	a = int(a)
	p = int(p)

	caracteristics = [True for i in range(p)]

	for i in range(a):
		person = [True if int(i) == 1 else False for i in input().split()]
		for j in list(range(p)):
			caracteristics[j] = (person[j] and caracteristics[j])
	
	c = int(input())

	cont = 0
	for i in range(c):
		cel = [True if int(i) == 1 else False for i in input().split()]
		is_factible = True
		for j,k in zip(caracteristics, cel):
			if j == True and k == False:
				is_factible = False
				break;
		if is_factible:
			cont += 1;

	print(cont)


	