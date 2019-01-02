#! /usr/bin/env python3

casos = int(input())

ni = [0, -1, -1, -1 , 0,  1, 1, 1]
nj = [1,  1,  0, -1, -1, -1, 0, 1]

n, m = [2, 2]
mat      = [[] for x in range(n)]
mat_prev = [[] for x in range(n)]

def inside_vivo(i, j):
	# print(i, j, end=' ') 
	# if (0 <= i < n) and (0 <= j < m) :
	# 	print(mat_prev[i][j])
	# else:
	# 	print()

	if (0 <= i < n) and (0 <= j < m) and (mat_prev[i][j] == '*') :
		#print(" <-")
		return True
	else:
		#print()
		return False


def print_mat():
	for i in list(range(n)):
		for j in list(range(m)):
			print(mat[i][j], end='')			
		print()

def print_prev_mat():
	for i in list(range(n)):
		for j in list(range(m)):
			print(mat_prev[i][j], end='')			
		print()

#print_mat()


for caso in range(casos):
	n, m = [int(x) for x in input().split()]

	mat      = [[] for x in range(n)]
	mat_prev = [[] for x in range(n)]

	for i in list(range(n)):
		mat[i] = list(input())
		for j in list(range(m)):
			mat_prev[i].append( mat[i][j] )

	#print(mat)

	t = int(input())

	#print_mat()
	#print()
	for timestamp in range(t):
		for i in list(range(n)):
			for j in list(range(m)):
				#print(i, j, end=" ")
				vecinos = 0
				veclist = []
				for k in list(range(8)):
					if inside_vivo(i+ni[k], j+nj[k]):
						veclist.append((i+ni[k], j+nj[k]))
						vecinos += 1
				#assert(mat[i][j] == '.')
				#print(mat[i][j],vecinos, veclist)

				if mat[i][j] == '*':
					if vecinos < 2 or vecinos > 3:
						mat[i][j] = '.'
				else:
					
					if vecinos == 3:
						mat[i][j] = '*'


		for i in list(range(n)):
			for j in list(range(m)):
				mat_prev[i][j] = mat[i][j]

		#print_mat()
		#print()
	print_mat()

#print_mat()



