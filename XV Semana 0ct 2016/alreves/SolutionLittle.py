def es_palindromo(m):
	for i in list(range(len(m))):
		if m[i] != m[len(m)-i-1] :
			return False
	return True
	


n = int(input())
for x in range(n):
	a, b = [int(x) for x in input().split()]
	tot = 0
	for i in list(range(a, b+1)):
		#print(i, end = ' ')
		tot += es_palindromo(str(i))
		#print(tot)
	print(tot)