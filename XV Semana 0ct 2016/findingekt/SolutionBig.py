#! /usr/bin/env python3

cases = int(input())

mat = [[0 for j in range(60)] for i in range(60)]


for case in range(cases):
	n = int(input())

	for i in list(range(n)):
		mat[i] = [int(j) for j in input().split()]


	for k in list(range(n)):
		for i in list(range(n)):
			for j in list(range(n)):
				mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j])

	q = int(input())

	for query in range(q):
		s, t = [int(x) for x in input().split()]
		print(mat[s][t])